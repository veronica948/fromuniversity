package by.bsu.mmf.mashenkova.ElectricalAppliancesSERIALIZATION;

import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: user
 * Date: 10.05.14
 * Time: 18:52
 * To change this template use File | Settings | File Templates.
 */
public class Serializator {
    public boolean serialization(ElectricalAppliance appl, String fileName) {
        boolean flag = false;
        File file = new File(fileName);
        ObjectOutputStream os = null;
        try {
            FileOutputStream fos = new FileOutputStream(file);
            if(fos != null) {
                os = new ObjectOutputStream(fos);
                os.writeObject(appl);
                flag = true;
            }
        } catch(FileNotFoundException e) {
            System.out.println(e);
        } catch(NotSerializableException e) {
            System.out.println(e);
        } catch (IOException e) {
            System.out.println(e);
        } finally {
            try {
                if(os != null) {
                    os.close();
                }
            } catch (IOException e) {
                System.out.println(e);
            }
        }
        return flag;
    }

    public ElectricalAppliance deserialization(String fileName) throws InvalidObjectException{
        File file = new File(fileName);
        ObjectInputStream is = null;
        try {
            FileInputStream fis = new FileInputStream(file);
            is = new ObjectInputStream(fis);
            ElectricalAppliance appl = (ElectricalAppliance) is.readObject();
            return appl;
        } catch (ClassNotFoundException e) {
            System.out.println(e);
        } catch (FileNotFoundException e) {
            System.out.println(e);
        } catch(InvalidClassException e) {
            System.out.println(e);
        } catch(IOException e) {
            System.out.println(e);
        } finally {
            try {
                if(is != null) {
                    is.close();
                }
            } catch (IOException e) {
                System.out.println(e);
            }
        }
        throw new InvalidObjectException("Object not desirialized.");
    }
}
