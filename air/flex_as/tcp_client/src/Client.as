package
{
	import flash.events.Event;
	import flash.events.IOErrorEvent;
	import flash.events.ProgressEvent;
	import flash.net.Socket;
	import flash.events.NetStatusEvent;
    import flash.events.SecurityErrorEvent;
	import spark.components.TextArea;
	
	/**
	 * ...
	 * @author test
	 */
	public class Client 
	{
		private var ip:String = null;
		private var port:String = null;
		private var socket:Socket;
		private var txtAreaRcvdData:TextArea;
		
		public function Client():void {
			socket = new Socket();
            socket.addEventListener(Event.CLOSE, closeHandler);
            socket.addEventListener(Event.CONNECT, connectHandler);
            socket.addEventListener(IOErrorEvent.IO_ERROR, ioErrorHandler);
            socket.addEventListener(SecurityErrorEvent.SECURITY_ERROR, securityErrorHandler);
            socket.addEventListener(ProgressEvent.SOCKET_DATA, socketDataHandler);
		}
		
		public function setIpAddress(ip:String):void {
			this.ip = ip;
		}
		
		public function setPortNumber(port:String):void {
			this.port = port;
		}
		
		public function setRcvdTxtArea(txtAreaRcvdData:TextArea):void {
			this.txtAreaRcvdData = txtAreaRcvdData;
		}
		
		public function connect():Boolean {
			var returnValue: Boolean = false;
			
			if (!socket.connected && (ip != null) && (port != null)) {
				socket.connect(ip, parseInt(port, 10));
				returnValue = true;
			}
			
			return (returnValue);
		}
		
		public function disconnect():void {
			if (socket.connected) {
				socket.close();
			}
		}
		
		public function sendUTFBytes(data:String):void {
			if (socket.connected) {
				socket.writeUTFBytes(data);
				socket.flush();
			}
		}
		
		private function closeHandler(event:Event):void {
			trace("Connection closed...");			
		}
		
		private function connectHandler(event:Event):void {
			trace("Connection established...");
		}
		
		private function ioErrorHandler(event:IOErrorEvent):void {
			trace("IO Error...");
		}
		
		private function securityErrorHandler(event:SecurityErrorEvent):void {
			trace("Security Error...");
		}
		
		private function socketDataHandler(event:ProgressEvent):void {
            var data:String;
			
			if (null != txtAreaRcvdData) {
				data = txtAreaRcvdData.text;
				data += (new Date()).getHours() + ":" + (new Date()).getMinutes() + ":" + (new Date()).getSeconds() + ": ";
				data += socket.readUTFBytes(socket.bytesAvailable) + "\r\n";
				txtAreaRcvdData.text = data;
			}
            
		}
	}
	
}