public class GenericProduct implements Product {
    int productId;
    String productName;
    int quantity;

    GenericProduct(int productId,
            String productName,
            int quantity) {

        this.productId = productId;
        this.productName = productName;
        this.quantity = quantity;

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
}
