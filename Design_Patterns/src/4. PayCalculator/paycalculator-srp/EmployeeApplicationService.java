public class EmployeeApplicationService {
    private final InMemoryRepository repo;

    public EmployeeApplicationService() {
        this.repo = InMemoryRepository.getInstance();
    }

    public void update(String id, int work, int overtime) {
        Employee emp = repo.getEmployee(id);

        emp.setWorkingHours(emp.getWorkingHours() + work);
        emp.setOvertimeHours(emp.getOvertimeHours() + overtime);

        repo.writeEmployee(emp);
    }

    public int calculatePayment(String id, int work, int overtime) {
        Employee emp = repo.getEmployee(id);

        emp.setWorkingHours(emp.getWorkingHours() + work);
        emp.setOvertimeHours(emp.getOvertimeHours() + overtime);
        return emp.calculatePayment();
    }

    public Employee findEmployee(String id) throws EmpoyeeNotFoundException {
        Employee emp = repo.getEmployee(id);
        if (emp == null) throw new EmpoyeeNotFoundException();
        return emp;
    }

    public void printEmployees() {
        repo.printEmployees();
    }
}
