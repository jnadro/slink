var WebSocket = require('ws'),
	url = 'http://localhost:8080';
	Slink = require('./slink'),
	Test = require('./test');



ws.on('open', function() {
	console.log('connection made to '+ server);

	ws.send('Handshake');
});

ws.on('message', function(data, flags) {
	console.log(data);
});

var b = document.getElementById('draw');
b.onclick = function() {
	ws.send("DrawCommand");
};