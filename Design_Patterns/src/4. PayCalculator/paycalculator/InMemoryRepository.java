import java.util.HashMap;

public class InMemoryRepository {
    private static InMemoryRepository instance;
    private HashMap<String, Employee> map;
    private InMemoryRepository() {
        map = new HashMap<>();
    }
    public static InMemoryRepository getInstance() {
        if (instance == null)
            instance = new InMemoryRepository();
        return instance;
    }

    public void createEmployee(String id) {
        if(!map.containsKey(id))	//키가 들어있는지 확인. 있으면 덮어쓰지 않는다.
            map.put(id, new Employee(id));
    }

    public Employee getEmployee(String id) {
        return map.get(id);
    }

    public Employee writeEmployee(Employee emp) {
        map.put(emp.getId(), emp);
        return map.get(emp.getId());
    }

    public void printEmployees() {
        map.forEach((key, emp) -> {
            System.out.println(
                    String.format("키 -> %s, 정상근무시간 -> %s, 초과근무시간 -> %s",
                            key, emp.getWorkingHours(), emp.getOvertimeHours())
            );
        });
    }
}
