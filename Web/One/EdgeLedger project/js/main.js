var map;

function initMap() {
  map = new google.maps.Map(document.querySelector('.map'), {
    center: {
      lat: -40,
      lng: 70
    },
    zoom: 8
  });
}


// Smooth Scrolling

$('#navbar a, .btn').on('click', function(event) {
  if(this.hash != ''){
    event.preventDefault();

    const hash = this.hash;

    $('html, body ').animate(
      {
        scrollTop: $(hash).offset().top -100
      },
      800
    );
  }
});