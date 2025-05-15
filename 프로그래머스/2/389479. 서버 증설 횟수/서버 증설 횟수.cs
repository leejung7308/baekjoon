using System;
using System.Collections.Generic;

public class Solution {
    public int solution(int[] players, int m, int k) {
        int answer = 0;
        int[] servers = new int[24];
        for(int i=0;i<24;i++){
            int q = players[i]/m;
            if(q<=servers[i]) continue;
            int p = q-servers[i];
            answer+=p;
            for(int j=i; j<i+k && j<24; j++) servers[j]+=p;
        }
        return answer;
    }
}