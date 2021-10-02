package good.server;

public class FastServer implements Server {
    @Override
    public void foo() {
        System.out.println("fast server is running!");
    }
}