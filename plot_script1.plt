set title 'Graphe des algorithmes de tri par la fonction de Gauss'
plot [1000:15000]0.001347*exp(-(((x-7618.529297)/1861.249878)**2)/2) title 'Tri par Insertion',0.001251*exp(-(((x-7506.581543)/2004.315674)**2)/2) title 'Tri par Selection',0.001294*exp(-(((x-6413.779297)/1937.631592)**2)/2) title 'Tri par Tas',0.001426*exp(-(((x-7756.250000)/1757.635254)**2)/2) title 'Tri Rapide',0.001232*exp(-(((x-7313.792969)/2034.075928)**2)/2) title 'Tri Fusion',0.001317*exp(-(((x-7617.307129)/1902.823486)**2)/2) title 'Tri Bulle'