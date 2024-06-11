abstract class Product {
    private String name;
    private double weight;

    public Product(String name, double weight) {
        this.name = name;
        this.weight = weight;
    }

    public String getName() {
        return name;
    }

    public double getWeight() {
        return weight;
    }

    public abstract double calculateAmount(int numberOfPies);
}

class Eggs extends Product {
    public Eggs() {
        super("Яйца", 100);
    }

   
    public double calculateAmount(int numberOfPies) {
        return getWeight() * numberOfPies;
    }
}

class Flour extends Product {
    public Flour() {
        super("Мука", 400);
    }

    
    public double calculateAmount(int numberOfPies) {
        return getWeight() * numberOfPies;
    }
}

class Sugar extends Product {
    public Sugar() {
        super("Сахар", 150);
    }

    
    public double calculateAmount(int numberOfPies) {
        return getWeight() * numberOfPies;
    }
}

class Cherry extends Product {
    public Cherry() {
        super("Вишня", 500);
    }

    
    public double calculateAmount(int numberOfPies) {
        return getWeight() * numberOfPies;
    }
}

public class Products {
    public static void main(String[] args) {
        int numberOfPies = 1; // Количество пирогов

        Product eggs = new Eggs();
        Product flour = new Flour();
        Product sugar = new Sugar();
        Product cherry = new Cherry();

        System.out.println("Ингредиенты для пирога с вишней:");

        System.out.println("Яйца: " + eggs.calculateAmount(numberOfPies) + " грамм");
        System.out.println("Мука: " + flour.calculateAmount(numberOfPies) + " грамм");
        System.out.println("Сахар: " + sugar.calculateAmount(numberOfPies) + " грамм");
        System.out.println("Вишня: " + cherry.calculateAmount(numberOfPies) + " грамм");
    }
}
