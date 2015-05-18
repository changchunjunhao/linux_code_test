#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct {
  int integer;
  char string[24];
}RECORD;


//LEARN IT (), SQL inject attack
#define NRECORDS (100)

void store(char *filename) {
  RECORD record;
  int i, f;
  FILE *fp;
  
  fp = fopen(filename, "w+");
  for (i=0; i<NRECORDS; i++) {
    record.integer = i;
    sprintf(record.string, "RECORD-%d", i);
    fwrite(&record, sizeof(record), 1, fp);
  }
  fclose(fp);
}

void test_fread(char* filename,int index) { 
  FILE *fp;
  RECORD record;
  
  fp = fopen(filename, "r+");
  fseek(fp, index*sizeof(record), SEEK_SET);
  fread(&record, sizeof(record), 1, fp);
  
  printf("record %3d: %-10s\n", record.integer, record.string); 
  
  record.integer = 143;
  sprintf(record.string, "RECORD-%d", record.integer);

  fseek(fp, index*sizeof(record), SEEK_SET);
  fwrite(&record, sizeof(record), 1, fp);
  fclose(fp);
}

void test_mmap(char*filename, int index) { 
  int f;
  RECORD* mapped;
  f = open(filename, O_RDWR);
  mapped = (RECORD*)mmap(0, NRECORDS*sizeof(RECORD),
		 PROT_READ|PROT_WRITE, MAP_SHARED, f,0);
  mapped[index].integer = 243;
  sprintf(mapped[index].string, "RECORD-%d", mapped[index].integer);
  
  msync((void*)mapped, NRECORDS*sizeof(RECORD), MS_ASYNC);
  munmap((void*)mapped, NRECORDS*sizeof(RECORD));
  close(f);
}

int main()
{
  char filename[] = "records.dat";
  //  store(filename);
  // test_fread(filename, 43);
  test_mmap(filename, 43);
  printf("\ndone\n");
}
