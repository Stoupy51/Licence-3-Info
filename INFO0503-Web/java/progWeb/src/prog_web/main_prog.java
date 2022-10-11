
package prog_web;

import java.security.Timestamp;

public class main_prog {
    public main_prog() {}

    public static void main(String[] args) throws Exception {
        System.out.println("\n\n\n\n\nDébut de la fonction main()\n");
        Long time = System.currentTimeMillis();
        
        CodeDeSuivi code = new CodeDeSuivi("51;515;15");
        System.out.println("\n"+code+"\n");

        System.out.println("\nFin de la fonction main() en "+toString(System.currentTimeMillis()-time))+"ms\n");
    }
}

