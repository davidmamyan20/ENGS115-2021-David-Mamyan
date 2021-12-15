Project Data Converter (David Mamyan, Edgar Tonoyan)

1.Introduction

1.1 Document Identifier

Our project name is gitlog. The content of this document is a data converter program, which will show the gitlog command's actions on json, which information will be read while running the code on C. The project will be done by David Mamyan and Edgar Tonoyan.The project is available in ENGS-115-2021-David-Mamyan repository and its Project folder.

1.2 Scope

Introduction section provides overview of the document content as well as the brief
description of the project requirements. Section Definitions of terms and acronyms includes
description of all the terms and acronyms used in the document. Section References has
links to the documentation and sources used to build this document. Overview Section
briefly describes the requirements and purpose of the project. All the requirements are
described in subsections of Requirements section. The features that the project should
support are described in section Functional Requirements. Platform Requirements specifies
all the hardware and software requirements of the project, including hardware models and
operating system versions. Implementation Requirements section includes requirements on
the tools, libraries, applications, programming languages. Performance Requirements
section contains information of the performance of the developed product, in particular run-
time of the applications developed for the project. The methods used to verify the project
are specified in Verification Requirements section. Documentation Requirements project lists
all the documents that should be created for the project. Project Management section
includes Error: Reference source not found, Dependencies, Assumptions, Risks and Schedule
and Effort Estimations sections which describe the project state and estimations with
consideration of the dependencies and risks.

1.3 Definitions of terms and acronyms

Task - Well defined components of project work.
Team Member - The individuals, reporting to the project manager, about their actions during a brief of time. In our case we simply work together and only let each other know about the actions, when we are apart.
Testing - The actual test of the products or processes createdwithin the development phase of the project.
Schedule - The planned dates for performing activities and for meeting deliverables
Glossary – also known as a vocabulary, or clavis, is an alphabetical list of terms in a
particular domain of knowledge with the definitions for those terms.
Operating System - system software that manages computer hardware and software
resources and provides common services for computer programs.
Assumptions – things you assume are in place which contribute to the success of the project.
Dependencies – other projects or triggers that your project depends on, or are a beneficiary of your project outcomes.
Risks – events that can have an adverse impact if they occur.

1.4 References

https://github.com/davidmamyan20/ENGS115-2021-David-Mamyan.git
ENGS115-2021-David-Mamyan/Project

1.5 Overview

Our project is going to be a data converter type, where we will use git log and try to write put the results in the json and it must be run in the C code and the user should be able to read it. The requirements of this project are knowing how to write a code in C language, most important terms of the code which are required to know are the search and sort. There are also new libraries which will be required to use during the code.


2 Requirements

2.1 Functional Requirements

The code must be read on C, so that you could read the git log info while running the Code.
json file also must be used, because we will use the details of the git log as a json file.

2.2 Platform Requirements

Debian Linux
Mac OS
C library
Boolean Library
Json/c Library
String Library
However the complying won't be possible on Mac OS, so the code can be runned in Linux. To compile use gcc gitlog.c -ljson-c, then ./a.out. 

2.3 Implementation Requirements

C language
json

2.4 Performance Requirements

Complexity O(n^2).Because while it prints the gitlog command on json, it should also do the same actions converted to html, which will take n^2 steps. That's why the complexity is O(n^2).

2.5 Verification Requirements

The user isn't required to write anything, when it compiles, it will just show the results.

2.6 Documentation Requirements

The project should have a README file describing the meaning and usage of the project.
User guide should be provided where the tool installation, usage of all the supported
features.

3 Project Management

3.1 Dependencies, Assumptions, Risks

Risk that can occur are that the consumer took a wrong library or an operator to see the converted data or could not convert the data.

3.2 Schedule and Effort Estimations

The project will be a json file available in C while running the code, where the user will enter the git log command, and the results will be shown in the result of running a C code. 
(Optional) There will be a filtre, where there will only be written the name and the surname of the person who entered the git log command.

3.3 Aceptance Criteria

The acceptance criteria is seeing our commits on C, after compiling.

3.4 Report
Edgar Tonoyan - implemented the array_create(), array_swap(), function, created the presentation, created the json file, the presentation and the video is uploaded by Edgar.
David Mamyan - implemented the json parsing code in C, the print function, the test function, array_insert(). Worked on the presentation and recorded the video.
Both of us worked on PRD.

3.5 Warning
In the recording there was an issue with compiling, but then we compiled it again and there were no errors.
