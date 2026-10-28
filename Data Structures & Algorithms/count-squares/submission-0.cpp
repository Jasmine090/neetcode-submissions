class CountSquares {
public:
    int map[1001][1001] = {0};  
    CountSquares() {
        
    }
    
    void add(vector<int> point) {
        map[point[0]][point[1]]++;
    }
    
    int count(vector<int> point) {
        int re = 0;
        int x = point[0];
        int y = point[1];
        for(int i=1;i<1001;i++){
            int px, py;
            // ++
            px = x+i;
            py = y+i;
            if(px>=0 && px<=1000 && py>=0 && py<=1000){
                re += map[px][py]*map[x][py]*map[px][y];
            }
            // +-
            px = x+i;
            py = y-i;
            if(px>=0 && px<=1000 && py>=0 && py<=1000){
                re += map[px][py]*map[x][py]*map[px][y];
            }
            // --
            px = x-i;
            py = y-i;
            if(px>=0 && px<=1000 && py>=0 && py<=1000){
                re += map[px][py]*map[x][py]*map[px][y];
            }
            // -+
            px = x-i;
            py = y+i;
            if(px>=0 && px<=1000 && py>=0 && py<=1000){
                re += map[px][py]*map[x][py]*map[px][y];
            }
        }
        return re;
    }
};
