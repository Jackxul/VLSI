# Lesson 3
HW3
---
part 1

    heuristic algorithm  依照問題特性來想解決方法（通常不會是最佳解法）
    call glkp api
    GNU glpk
part 2

    ILP slover (gnu glkp)    
BLIF(Boolean file) Gate

    111 AND gate
    01  Not gate
    1-- Or  gate
---

### Constrained Scheduling Algo
---
ML-RCS (NP-Complete)  Minimize latency given constrains on area or the resources
        
    講求latency最佳化(有富爸爸贊助)
MR-LCS :  Minimize resources subject to bound on latency 

    節省硬體能耗（硬體資源有限）

---
##### Hu's Algorithm 
    Find the longest path passing through the vertex(最長路徑先做) 
##### List Scheduling
    Greedy algorithm for ML-RCS and MR-LCS
    
    ML-RCS:
        q=list algorithm scheduling in C
ILP(幼稚園小朋友分群問題)
    
    4個小朋友 --> 分兩群 --> 不是在第一群就是在第二群 --> 共8種變數
ILP Formulation
    
    Constraints:
        - Unique start times
        - Sequencing(dependency) relations must be satisfied
        - Resource contraints
    Objective : 
        

