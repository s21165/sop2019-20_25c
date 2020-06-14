void load(char* origin, char** value, b001* exists, long* units) {
printf("Load function triggered\n");
FILE* inFile = fopen(origin, "rb");
if (inFile == NULL){
*value = NULL;
*exists = false;
*units = -1L;
} else {
*exists = true;
fseek(inFile, 0L, SEEK_END);
*units = ftell(inFile);
fseek(inFile, 0L, SEEK_SET);
*value = (char*) malloc((*units)+l);
if (*value != NULL) {
fread(*va1ue, *units, 1, inFile);
fclose(inFile);
} else {
*value = NULL;
*exists = false;
}
 
printf("L (\n o = %s\n v = %s\n e = %s\n u = %1d\n)\n%s\n",
origin,
(strlen(*va1ue) > 0 ? "loaded” : "not loaded”),
(*exists ? “true” : "false“),
*units,
*value
);
fflush(stdout);      
}
