public class Main {
    public static void main(String[] args) throws OutofStockException {
        Inventory<GenericProduct> genericInventory = new Inventory<>(10);
        GenericProduct g1 = new GenericProduct(1, "Gen 1", 5);
        genericInventory.addProduct(g1);
        Inventory<ElectronicsProduct> electronicInventory = new Inventory<>(10);
        ElectronicsProduct e1 = new ElectronicsProduct(1, "Micro", 10, "Samsung");
        genericInventory.processOrder(1, 2);
        electronicInventory.addProduct(e1);

        electronicInventory.processOrder(2, 3);
        electronicInventory.processOrder(1, 30);

    }
}
