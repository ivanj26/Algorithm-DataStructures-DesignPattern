package bad.client;

import bad.server.Server;
import bad.server.FastServer;

public class Client {
    private Server server;
    private FastServer fastServer;

    public Client(Server _server) {
        this.server = _server;
    }

    public Client(FastServer _fastServer) {
        this.fastServer = _fastServer;
    }

    public void start() {
        if (server != null) {
            server.foo();
        }

        if (fastServer != null) {
            fastServer.foo();
        }
    }
}
