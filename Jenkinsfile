pipeline {
    agent any 
    stages {
        stage('Build') { 
            steps {
                sh 'gcc -I. main.c mergsort.c quicksort.c tview.c -o run'
            }
        }  
    }
}
