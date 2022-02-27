
class handphone{
    protected String brand, name, os_version, chipset, ram, storage;
}

class android extends handphone{
    android (String b, String n, String v, String c, String r, String s){
        brand = b;
        name = n;
        os_version=v;
        chipset = c;
        ram = r;
        storage = s;
        System.out.println("Adding data...");
    }
    public void print_spesification(){
        System.out.println("\nBrand           : "+brand);
        System.out.println("Name            : "+name);
        System.out.println("Android Version : "+os_version);
        System.out.println("Chipset         : "+chipset);
        System.out.println("RAM             : "+ram);
        System.out.println("Storage         : "+storage);
    }
}

class ios extends handphone{
    ios (String b, String n, String v, String c, String r, String s){
        brand = b;
        name = n;
        os_version=v;
        chipset = c;
        ram = r;
        storage = s;
        System.out.println("Adding data...");
    }
    public void print_spesification(){
        System.out.println("\nBrand           : "+brand);
        System.out.println("Name            : "+name);
        System.out.println("IOS Version     : "+os_version);
        System.out.println("Chipset         : "+chipset);
        System.out.println("RAM             : "+ram);
        System.out.println("Storage         : "+storage);
    }
}


class main{
    public static void main(String[] args) {
        System.out.println("\n=== PROGRAM PENERAPAN CLASS DAN INHERITANCE DALAM BAHASA PEMROGRAMAN JAVA ===\n");
        System.out.println("\nIlustrasi menggunakan inheritance handphone\n");
        android hp1 = new android(
        "Xiaomi",
        "Xiaomi Redmi Note 8 Pro",
        "Android 9.0 (Pie), upgradable to Android 11, MIUI 12.5",
        "Mediatek Helio G90T (12nm)",
        "4-8 GB",
        "64-256 GB"
        );
        ios hp2 = new ios(
        "Apple",
        "Apple iPhone X",
        "iOS 11.1.1, upgradable to iOS 15.2",
        "Apple A11 Bionic (10 nm)",
        "3 GB",
        "64 and 256 GB"
        );
        android hp3 = new android(
        "Oppo",
        "Oppo F11",
        "Android 9.0 (Pie), ColorOS 6",
        "Mediatek MT6771 Helio P70 (12nm)",
        "4-6 GB",
        "64-128 GB"
        );
        ios hp4 = new ios(
        "Apple",
        "Apple iPhone 11",
        "iOS 13, upgradable to iOS 15.2",
        "Apple A13 Bionic (7 nm+)",
        "4 GB",
        "64-256 GB"
        );
        System.out.println("\nPrinting...");
        hp1.print_spesification();
        hp2.print_spesification();
        hp3.print_spesification();
        hp4.print_spesification();
        System.out.println("");
    }
}



