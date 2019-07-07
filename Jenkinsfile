pipeline {
    agent any 
    stages {
        stage('Static analysis) {
            steps {
                sh 'cppcheck --xml --xml-version=2 2> cppcheck.xml'
            }
        }
        stage('Build') { 
            steps {
                sh 'gcc -I. main.c mergsort.c quicksort.c tview.c -o run'
            }
        }  
    }
}
