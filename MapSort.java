import java.util.*;

public class Main {
    public static void main(String[] args) {
        HashMap<Integer, String> map = new HashMap<>();
        map.put(3, "BMW");
        map.put(1, "Tesla");
        map.put(2, "Audi");

        // Convert HashMap to List
        List<Map.Entry<Integer, String>> list = new ArrayList<>(map.entrySet());

        // Sort List by Values
        Collections.sort(list, new Comparator<Map.Entry<Integer, String>>() {
            public int compare(Map.Entry<Integer, String> e1, Map.Entry<Integer, String> e2) {
                return e1.getValue().compareTo(e2.getValue());
            }
        });

        // Store sorted data in LinkedHashMap
        LinkedHashMap<Integer, String> sortedMap = new LinkedHashMap<>();
        for (Map.Entry<Integer, String> entry : list) {
            sortedMap.put(entry.getKey(), entry.getValue());
        }

        // Print the sorted map
        System.out.println("Sorted by Values:");
        for (Map.Entry<Integer, String> entry : sortedMap.entrySet()) {
            System.out.println(entry.getKey() + " -> " + entry.getValue());
        }
    }
}