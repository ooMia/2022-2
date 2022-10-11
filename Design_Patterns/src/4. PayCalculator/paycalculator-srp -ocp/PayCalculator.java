public interface PayCalculator {
    default int calculatePayment(int workingHours, int overtimeHours) {
        return 10000 * workingHours + 15000 * overtimeHours;
    }
}

