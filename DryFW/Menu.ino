int clavier() {

  int entree = digitalRead(BOUTON_OK_PIN);
  int haut = digitalRead(BOUTON_UP_PIN);
  int bas = digitalRead(BOUTON_DOWN_PIN);


 
  
  if (entree == HIGH) {         
    delay(100);       
    return 1;          
  }

  if (haut == HIGH) {   
    delay(100);            
    return 2;          
  }

  if (bas == HIGH) {    
    delay(100);              
    return 3;           
  }

  return 0;             

}

