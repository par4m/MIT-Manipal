import java.util.ArrayList;

public class Inventory<T extends Product> {
    private ArrayList<T> productList;
    int max;

    Inventory(int max) {
        productList = new ArrayList<>();
        this.max = max;
    }

    public void addProduct(T p) {
        if (productList.size() <= max) {
            productList.add(p);
        } else {
            System.out.println("FULL. cannot add");
        }
    }

    public void processOrder(int productId, int quantity) throws OutofStockException {
        for (T x : productList) {
            if (x.getProductId() == productId) {
                if (x.getQuantity() >= quantity) {
                    int temp = x.getQuantity() - quantity;
                    x.updateQuantity(temp);
                    System.out.println("Order Processed");
                    return;
                } else {
                    throw new OutofStockException();
                }
            }
        }
        System.out.println("Product Not Found");

    }

}