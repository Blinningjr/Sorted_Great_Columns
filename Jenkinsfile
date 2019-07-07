pipeline {
    agent any 
    stages {
        stage('Static analysis') {
            steps {
                sh 'cppcheck --xml --xml-version=2 /var/lib/jenkins/workspace/Sorted_Great_Columns 2> cppcheck.xml'
                sh 'cppcheck-htmlreport --file=cppcheck.xml --report-dir=html_cppcheck --source-dir=.'
                publishHTML ([
                    reportName:'static_analysis',
                    reportDir:'html_cppcheck/' ]) 
            }
        }
        stage('Build') { 
            steps {
                sh 'gcc -I. main.c mergsort.c quicksort.c tview.c -o run'
            }
        }  
    }
}
