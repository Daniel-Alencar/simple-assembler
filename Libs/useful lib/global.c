char registers[][6] = {"$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1",
  "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", "$s0", "$s1", "$s2", "$s3",
  "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1", "$gp", "$sp", "$fp", "$ra"
};

//char **labels;
//int *labelsPositions;

char **labels;
int labelsPositions[20];

/*
labels = (char **) malloc(sizeof(char *) * 2);
for(i = 0; i < 2; i++) {
  labels[i] = (char *) malloc(sizeof(char) * 10);
}
labelsPositions = (int *) malloc(sizeof(int) * 10);

strcpy(labels[0], "for");
labelsPositions[0] = 5;
*/