import java.net.DatagramPacket;
import java.net.DatagramSocket;
import java.net.InetAddress;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    private static DatagramSocket socket;

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
            new Thread(new listener(socket)).start();
            while (scn.hasNextLine()) {
                line = scn.nextLine();
                tokens = line.split("\\s+");
                byte[] pkt = new Packet(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1]), PacketMode.values()[Integer.parseInt(tokens[2])],127).getBytes();
                DatagramPacket packet = new DatagramPacket(pkt, pkt.length, InetAddress.getByName("192.168.1.50"), 4210);
                socket.send(packet);
                System.out.println(byte_to_str(pkt));

            }
        } catch (Exception ex) {
            System.out.println("error");
        }
        socket.close();
    }
    public static enum PacketMode{
        STOP,MOVE,REVERSE_MOVE,GO_STRAIGHT,GO_BACK,TURN_RIGHT,TURN_LEFT
    }
    public static class Packet{
        private int angle,speed,seqNumber;
        private PacketMode mode;
        //speed 1-4 angle 0-180
        public Packet(int speed,int angle,PacketMode mode,int seqNumber){
            this.speed = speed-1;
            this.angle = angle/3;
            this.mode  = mode;
            this.seqNumber = seqNumber;
        }

        @Override
        public boolean equals(Object obj) {
            Packet other = (Packet)obj;
            if (this.speed == other.speed && this.angle == other.angle && this.mode == other.mode)
                return true;
            return false;
        }

        public byte[] getBytes(){
            byte[] return_value = new byte[4];
            seqNumber       = seqNumber%512;
            return_value[0] = (byte) 170;
            return_value[1] = (byte)((int)(speed<<6) + (int)(angle&0x3F));
            return_value[2] = (byte)((mode.ordinal()<<5) + (seqNumber/16));
            return_value[3] = (byte)(((seqNumber%16)<<4) + 10);
            return return_value;
        }
    }
    public static class listener implements Runnable{
        byte[] receive = new byte[100];
        private DatagramSocket socket;
        public listener(DatagramSocket socket){
            this.socket = socket;
        }
        public void run(){
            DatagramPacket dpPacket = new DatagramPacket(receive, receive.length);
            byte[] ackPack = new byte[2];
            while (true) {
                try {
                    socket.receive(dpPacket);
                    ackPack[0] = receive[0];
                    ackPack[1] = receive[1];
                    System.out.println("rcv   :"+byte_to_str(ackPack));
                } catch (Exception ex) { }
            }
        }
    }
}
