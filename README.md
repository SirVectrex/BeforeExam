# BeforeExam

Musterklausur Aufgabe 2: 
Loesung:

    int counter = 0;
    char helper = 0;
    char message [] = "iwr rtfeefn nus ehtue";
    printf("%s\n", message);
    for (;message[counter] != '\0';){
        if(message[counter] != ' ' && message[counter+1] != ' ' && message[counter+1] != '\0') {
            char helper = message[counter];
            message[counter] = message[counter + 1];
            message[counter + 1] = helper;
            counter += 2;
        }
        else{
            counter++;
        }
    }
    printf("%s", message);
