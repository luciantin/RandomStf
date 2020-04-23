
// Dimensions of sunburst.




var width = 750;


var height = 600;


var radius = Math.min(width, height) / 2;

// Breadcrumb dimensions: width, height, spacing, width of tip/tail.




var b = {


 w: 75, h: 30, s: 3, t: 10


};







// Mapping of step names to colors.


var colors = {


 "home": "#5687d1",


 "product": "#7b615c",


 "search": "#de783b",


 "account": "#6ab975",


 "other": "#a173d1",


 "end": "#bbbbbb"


};














// Total size of all segments; we set this later, after loading the data.




var totalSize = 0;







var vis = d3.select("#chart").append("svg:svg")


   .attr("width", width)


   .attr("height", height)


   .append("svg:g")


   .attr("id", "container")


   .attr("transform", "translate(" + width / 2 + "," + height / 2 + ")");







var partition = d3.layout.partition()


   .size([2 * Math.PI, radius * radius])


   .value(function(d) { return d.size; });







var arc = d3.svg.arc()


   .startAngle(function(d) { return d.x; })


   .endAngle(function(d) { return d.x + d.dx; })


   .innerRadius(function(d) { return Math.sqrt(d.y); })


   .outerRadius(function(d) { return Math.sqrt(d.y + d.dy); });







// Use d3.text and d3.csv.parseRows so that we do not need to have a header


// row, and can receive the csv as an array of arrays.


d3.text("visit-sequences.csv", function(text) {


 var csv = d3.csv.parseRows(text);


 var json = buildHierarchy(csv);


 createVisualization(json);


});

