class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] visited = new boolean[rooms.size()];
        Stack<Integer> keys = new Stack();
        keys.push(0);
        
        do{    
            
            int i = keys.pop();
            visited[i] = true;
            for(int x : rooms.get(i)){
                if(!visited[x]){
                    visited[x] = true;
                    keys.push(x);
                }
            }
            
        }while(!keys.isEmpty());        
        
        for(boolean room : visited){
            if(!room) return false;
        }
        
        return true;        
    }
}
