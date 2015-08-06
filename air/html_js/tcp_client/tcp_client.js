var tmp;
var socket;

function appLoad(){ 
    air.trace("Hello World"); 
    socket = new air.Socket();
    socket.addEventListener(air.Event.CLOSE, closeHandler);
    socket.addEventListener(air.Event.CONNECT, connectHandler);
    socket.addEventListener(air.IOErrorEvent.IO_ERROR, ioErrorHandler);
    socket.addEventListener(air.SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
    socket.addEventListener(air.ProgressEvent.SOCKET_DATA, socketDataHandler);
}

function closeHandler(event) {
    air.trace("disconnected");
}

function connectHandler(event) {
    air.trace("connected");
}

function ioErrorHandler(event) {
    air.trace("io error");
}

function securityErrorHandler(event) {
    air.trace("security error");
}

function socketDataHandler(event) {
    var txt = document.getElementById("dataRcvd").value;
    txt += (new Date).getHours() + ":" + (new Date).getMinutes() + ":" + (new Date).getSeconds() + ": ";
    txt += socket.readUTFBytes(socket.bytesAvailable) + "\r\n";
    document.getElementById("dataRcvd").value = txt;
}        

function connect() {
    air.trace("connect");
    if (socket.connected == false) {
        socket.connect("127.0.0.1", 17231);
        socket.writeUTFBytes("test");
    }
}

function disconnect() {
    air.trace("disconnect");
    if(socket.connected == true) {
        air.trace("close");
        socket.close();
    }
}

function send()
{
    var txt =  document.getElementById("dataToSend").value;
    air.trace("..." + document.getElementById("appendCR").checked);
    socket.writeUTFBytes(txt);
    socket.flush();
}