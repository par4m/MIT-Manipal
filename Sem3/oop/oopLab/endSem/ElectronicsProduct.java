public class ElectronicsProduct implements Product {
    int productId;
    String productName;
    int quantity;
    String brand;

    ElectronicsProduct(int productId,
            String productName,
            int quantity, String brand) {
        this.productId = productId;
        this.productName = productName;
        this.quantity = quantity;
        this.brand = brand;

    }

    public int getProductId() {
        return productId;
    }

    public String getProductName() {
        return productName;
    }

    public int getQuantity() {
        return quantity;
    }

    public void updateQuantity(int q) {
        quantity = q;
    }

    public void searchProductName(String productName) {

    }

    public String getBrand() {
        return brand;
    }
}
