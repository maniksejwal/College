interface Area {
    public void area(int l, int b);
}

interface Perimeter {
    public void perimeter(int l, int b);
}

class FigureRectangle implements Area, Perimeter {
    public void area(int l, int b) {
        System.out.println("Area = " + l * b);
    }

    @Override
    public void perimeter(int l, int b) {
        System.out.println("Perimeter = " + 2 * (l + b));
    }
}

public class Practical4b {
    public static void main(String[] args) {
        Area a = new FigureRectangle();
        a.area(5,4);
        Perimeter b = new FigureRectangle();
        b.perimeter(4,3);
        FigureRectangle r = new FigureRectangle();
        r.area(2,4);
        r.perimeter(3,2);
    }
}
