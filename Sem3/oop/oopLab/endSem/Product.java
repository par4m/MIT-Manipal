public interface Product {

    public int getProductId();

    public String getProductName();

    public int getQuantity();

    public void updateQuantity(int q);

    void searchProductName(String productName);

}
