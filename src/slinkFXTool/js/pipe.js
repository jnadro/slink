function Pipe() {
	var WebSocket = require('ws');
	var ws = null;

    function open(url, onOpen, requestHandler) {
		ws = new WebSocket(url);
		ws.on('open', onOpen);
		ws.on('message', requestHandler);
    }

    function send(cmd) {
    	ws.send('0');
    }

    this.open = open;
    this.send = send;
}
 
module.exports = new Pipe();