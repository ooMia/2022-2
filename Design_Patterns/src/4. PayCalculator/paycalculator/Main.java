public class Main {
    public static void main(String[] args) {
        CalculatePayMachine p = new CalculatePayMachine();
        InMemoryRepository repo = InMemoryRepository.getInstance();
        initRepo(repo);
        repo.printEmployees();
    }



    private static void initRepo(InMemoryRepository repo) {
        repo.createEmployee("1111");
        repo.createEmployee("2222");
        repo.createEmployee("3333");
        repo.createEmployee("4444");
        repo.createEmployee("5555");
    }
}
