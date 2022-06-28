public class JRAPL{
    public static native void initRAPL();
    public static native void closeRAPL();
    public static native int numCores();
    public static native double readCoreEnergy(int core);
    public static native double readPackageEnergy();
    //Main method for testing
    /*
    public static void main(String[] args){
        System.loadLibrary("JRAPL");
        initRAPL();
        int numCore = numCores();
        double[] coreE = new double[numCore];
        for (int i=0; i<numCore; i++){
            coreE[i] = readCoreEnergy(i);
        }
        double packE = readPackageEnergy();
        try{
            Thread.sleep(1000);
        } catch (Exception e){
            e.printStackTrace();
        }
        double coreSum = 0;
        for (int i=0; i<numCore; i++){
            coreE[i] = readCoreEnergy(i) - coreE[i];
            coreSum += coreE[i];
        }
        packE = readPackageEnergy()-packE;
        for (int i=0; i<numCore; i++){
            System.out.println("Core #" + i + ":\t" + coreE[i] + "W");
        }
        System.out.println("Core Sum:\t" + coreSum + "W");
        System.out.println("Package:\t" + packE + "W");


    }
    */
}