package Day2;


import java.io.BufferedReader;

import java.io.FileReader;
import java.io.IOException;
import java.util.HashMap;

public class CubeConundrum {

    private static final HashMap<String, Integer> limits = new HashMap<String, Integer>();

    public static void main(String[] args) {

        limits.put("red", 12);
        limits.put("green", 13);
        limits.put("blue", 14);

        try {

            BufferedReader inputStream = new BufferedReader(new FileReader("resources/" + args[0]));
            String line = inputStream.readLine();

            int sum = 0;

            while (line != null) {
                sum += checkLimits(line);

                System.out.println(sum);
                line = inputStream.readLine();
            }

        }catch(IOException e){
            e.printStackTrace();
        }

    }

    private static int checkLimits(String line){

        int id = Integer.parseInt(line.split(" ")[1].replace(":", ""));

        line = line.split(":")[1];

        for(String count : line.split(";")){

            for(String cube: count.split(",")) {

               int x = Integer.parseInt(cube.split(" ")[1]);
               String colour = cube.split(" ")[2];

               if(x > limits.get(colour)){
                   return 0;
               }

            }
        }

        return id;
    }

}
