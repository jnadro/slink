function Pipe() {
	var ws = null;

    function open(url) {
		ws = new WebSocket(url);
    }

    function sendCmd(cmd) {

    }

    this.open = open;
    this.sendCmd = sendCmd;
}
 
module.exports = new Pipe();