var Pipe = require('./js/pipe'),
	url = 'http://localhost:8080';
	Slink = require('./slink');

var requestHandler = function(data, flags) {
	console.log(data);
};

var onOpen = function() {
	console.log('connection made to '+ url);

	Pipe.send('Handshake');
};

Pipe.open(url, onOpen, requestHandler);

var b = document.getElementById('draw');
b.onclick = function() {
	Pipe.send('0');
};