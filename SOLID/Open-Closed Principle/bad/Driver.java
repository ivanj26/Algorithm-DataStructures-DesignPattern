package bad;

import bad.client.Client;
import bad.server.FastServer;

public class Driver {
    public static void main(String[] args) {
        FastServer server = new FastServer();
        Client client = new Client(server);

        client.start();
    }
}
