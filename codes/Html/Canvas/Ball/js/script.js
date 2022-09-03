var canvas = document.getElementById('canvas');
var context = canvas.getContext('2d');

var radius = 20;
var color = "#0000ff";
var g = 0.1;
var x = 50;
var y = 50;
var vx = 2;
var vy = 10;

window.onload = init;

function init() {
  setInterval(main, 1000/60); // 60 fps
};

function main() {
    vy += g; // increase vertical velocity
    x += vx; // increase position based on velocity
    y += vy; // a velocidade vertical aumenta a posição vertical

    if (y > canvas.height - radius){ // If ball reach the floor then
        y = canvas.height - radius; // Reposition ball
        vy *= -0.8; // Revert direction and reduce velocity.
    } else if (y < radius){
        y = radius; // Reposition ball
        vy *= -1.0; // Revert direction
    }

    if (x > canvas.width - radius){
        x = canvas.width - radius; // Reposition ball
        vx *= -0.8;
    } else if (x < radius){
        x = radius; // Reposition ball
        vx *= -0.8;
    }
    drawBall();
};

function drawBall() {
    with (context){
        clearRect(0, 0, canvas.width, canvas.height);
        fillStyle = color;
        beginPath();
        arc(x, y, radius, 0, 2*Math.PI, true);
        closePath();
        fill();
    };
};