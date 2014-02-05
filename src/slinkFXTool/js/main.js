var WebSocket = require('ws');
var ws = new WebSocket('http://localhost:8080');
console.log('ready...');
ws.on('open', function() {
	ws.send('something');
});
ws.on('message', function(data, flags) {
	console.log(data);
});