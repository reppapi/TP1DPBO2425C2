public class Electronic {
    // atribut private
    private int id;
    private String name;
    private String type;
    private double price;
    private String imagePath;

    // constructor
    public Electronic(int id, String name, String type, double price, String imagePath) {
        this.id = id;
        this.name = name;
        this.type = type;
        this.price = price;
        this.imagePath = imagePath;
    }

    // getter & setter
    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getType() {
        return type;
    }

    public void setType(String type) {
        this.type = type;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String getImagePath() {
        return imagePath;
    }

    public void setImagePath(String imagePath) {
        this.imagePath = imagePath;
    }
}