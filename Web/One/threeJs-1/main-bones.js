import * as THREE from './node_modules/three/build/three.module.js';

import { GeometryUtils } from './node_modules/three/examples/jsm/utils/GeometryUtils.js';

THREE.Cache.enabled = true;

var container;

var camera, cameraTarget, scene, renderer;

var group, textMesh1, textMesh2, textGeo, materials;

var firstLetter = true;

var text = "NOP",

    height = 20,
    size = 70,
    hover = 30,

    curveSegments = 4,

    bevelThickness = 2,
    bevelSize = 1.5,
    bevelEnabled = true,

    font = undefined,

    fontName = "optimer", // helvetiker, optimer, gentilis, droid sans, droid serif
    fontWeight = "bold"; // normal bold

var mirror = true;

var fontMap = {

    "helvetiker": 0,
    "optimer": 1,
    "gentilis": 2,
    "droid/droid_sans": 3,
    "droid/droid_serif": 4

};

var weightMap = {

    "regular": 0,
    "bold": 1

};

 

init();
animate();



function init() {

    container = document.createElement('div');
    document.body.appendChild(container);


    // CAMERA

    camera = new THREE.PerspectiveCamera(30, window.innerWidth / window.innerHeight, 1, 1500);
    camera.position.set(0, 400, 700);

    cameraTarget = new THREE.Vector3(0, 150, 0);

    // SCENE

    scene = new THREE.Scene();
    scene.background = new THREE.Color(0x000000);
    scene.fog = new THREE.Fog(0x000000, 250, 1400);

    // LIGHTS

    var dirLight = new THREE.DirectionalLight(0xffffff, 0.125);
    dirLight.position.set(0, 0, 1).normalize();
    scene.add(dirLight);

    var pointLight = new THREE.PointLight(0xffffff, 1.5);
    pointLight.position.set(0, 100, 90);
    scene.add(pointLight);

    // Get text from hash

    text = 'Bravo';


    materials = [
        new THREE.MeshPhongMaterial({
            color: 0xf55fff,
            flatShading: false
        }), // front
        new THREE.MeshPhongMaterial({
            color: 0xf55ff5
        }) // side
    ];

    group = new THREE.Group();
    group.position.y = 100;

    scene.add(group);
    // device-widthdevice-width
    loadFont();

    renderer = new THREE.WebGLRenderer({
        antialias: true
    });
    renderer.setPixelRatio(window.devicePixelRatio);
    renderer.setSize(window.innerWidth, window.innerHeight);

    

    container.appendChild(renderer.domElement);

}


function loadFont() {
    var loader = new THREE.FontLoader();
    loader.load('node_modules/three/examples/fonts/' + fontName + '_' + fontWeight + '.typeface.json', function (response) {
        font = response;
        createText();
    });
}

function createText() {

    textGeo = new THREE.TextGeometry(text, {

        font: font,

        size: size,
        height: height,
        curveSegments: curveSegments,

        bevelThickness: bevelThickness,
        bevelSize: bevelSize,
        bevelEnabled: bevelEnabled

    });

    textGeo.computeBoundingBox();
    textGeo.computeVertexNormals();


    var centerOffset = -0.5 * (textGeo.boundingBox.max.x - textGeo.boundingBox.min.x);

    textGeo = new THREE.BufferGeometry().fromGeometry(textGeo);

    textMesh1 = new THREE.Mesh(textGeo, materials);
    textMesh2 = new THREE.Mesh(textGeo, materials);

    textMesh1.position.x = centerOffset;
    textMesh1.position.y = hover;
    textMesh1.position.z = 0;
    textMesh1.rotation.x = 0;
    textMesh1.rotation.y = 0;

    group.add(textMesh1);

    textMesh2.position.x = centerOffset+250;
    textMesh2.position.y = hover;
    textMesh2.position.z = 20;
    textMesh2.rotation.x = 0;
    textMesh2.rotation.y = 0;
    
    group.add(textMesh2);


}



function animate() {
    requestAnimationFrame(animate);
    render();
}

function render() {
    camera.lookAt(cameraTarget);

    renderer.clear();

    renderer.render(scene, camera);
}