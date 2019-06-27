abstract class Figure {
    double a1, a2;

    Figure(double dim1, double dim2) {
        a1 = dim1;
        a2 = dim2;
    }

    abstract void area();
}

class Rectangle extends Figure {

    Rectangle(double dim1, double dim2) {
        super(dim1, dim2);
        System.out.println("inside rectangle");
    }

    @Override
    void area() {
        System.out.println("Area = " + a1 * a2);
    }
}

class Triangle extends Figure {

    Triangle(double dim1, double dim2) {
        super(dim1, dim2);
        System.out.println("inside triangle");
    }

    @Override
    void area() {
        System.out.println("Area = " + a1 * a2 * 0.5);
    }
}

public class Practical4a {
    public static void main(String[] args) {
        Figure f = new Rectangle(1, 2);
        f.area();
        f = new Triangle(3, 4);
        f.area();
    }
}
