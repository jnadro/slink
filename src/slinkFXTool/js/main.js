var WebSocket = require('ws');

var ws = new WebSocket('http://localhost:8080');
console.log('ready...');
ws.on('open', function() {
	console.log('open');
	ws.send('something');
});
ws.on('message', function(data, flags) {
	console.log(data);
});

var b = document.getElementById('draw');
b.onclick = function() {
	ws.send("DrawCommand");
};