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

class Persons extends Product {
    public Persons() {
        super("Персоны", 6);
    }
    
    public double calculateAmount(int numberOfPies) {
    return getWeight() * numberOfPies;
    }
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
        Product persons = new Persons();

        double totalEggs = eggs.calculateAmount(numberOfPies);
        double totalFlour = flour.calculateAmount(numberOfPies);
        double totalSugar = sugar.calculateAmount(numberOfPies);
        double totalCherry = cherry.calculateAmount(numberOfPies);
        double totalPersons = persons.calculateAmount(numberOfPies);

        System.out.println("Необходимые ингредиенты для " + numberOfPies + " пирога:");
        System.out.println("Яйца: " + totalEggs + " г");
        System.out.println("Мука: " + totalFlour + " г");
        System.out.println("Сахар: " + totalSugar + " г");
        System.out.println("Вишня: " + totalCherry + " г");
        System.out.println("Необходимое количество персон: " + totalPersons);
    }
}
