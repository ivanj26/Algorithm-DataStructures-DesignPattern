package good.client;

import good.server.Server;

public class Client {
	private Server server;

	public Client(Server _server) {
		this.server = _server;
	}

	public void start() {
		server.foo();
	}
}
