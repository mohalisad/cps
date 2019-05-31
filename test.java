import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Scanner;

public class Main {
    private static DatagramSocket socket;
    //speed 1-4 angle 0-180
    public static byte[] make_packet(int speed,int angle,Mode mode){
        byte[] return_value = new byte[2];
        return_value[0] = (byte)((int)((speed-1)<<6) + (int)((angle/3)&0x3F));
        return_value[1] = (byte)(mode.ordinal()<<5);
        return return_value;
    }
    public static String byte_to_str(byte[] bytes){
        StringBuilder sb = new StringBuilder();
        for (byte b : bytes) {
            sb.append(String.format("%02X ", b));
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);
        String line;
        String[] tokens;
        try {
            socket = new DatagramSocket(4110);
            while (scn.hasNextLine()) {
                line = scn.nextLine();
                tokens = line.split("\\s+");
                byte[] pkt = make_packet(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), Mode.values()[Integer.parseInt(tokens[2])]);
                    DatagramPacket packet = new DatagramPacket(pkt, pkt.length, InetAddress.getByName("192.168.1.50"), 4210);
                    socket.send(packet);
                    System.out.println(byte_to_str(pkt));

            }
        } catch (Exception ex) {
            System.out.println("error");
        }
        socket.close();
    }
    public static enum Mode{
        STOP,MOVE,REVERSE_MOVE,GO_STRAIGHT,GO_BACK,TURN_RIGHT,TURN_LEFT
    }
}
