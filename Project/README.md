Project Data Converter (David Mamyan, Edgar Tonoyan)

1.Introduction

1.1 Document Identifier

Our project name is gitlog. The content of this document is a data converter program, which will show the gitlog command's actions on json, which information will be converted to html, so the reader couldsee the information via html on firedox.TThe project will be done by David Mamyan and Edgar Tonoyan.The project is available in ENGS-115-2021-David-Mamyan repository and its Project folder.

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

Our project is going to be a data converter type, where we will use git log and try to write put the results in the json and change it to html, so that the viewer could read the git log results in html by using Firefox, for example. At first we will do with no filters, and we may also use filters for the second try, for example in a way that there could be written only the name of the person who used the git log command.The requirements of this project are knowing how to write a code in C language, most important terms of the code which are required to know are the search and sort.


2 Requirements

2.1 Functional Requirements

The code must be read on html, so that you could read the git log info on html via firefox.
json file also must be used, because we will use the details of the git log as a json file.

2.2 Platform Requirements

Debian Linux
Mac OS

2.3 Implementation Requirements

C language
json
html
Git

2.4 Performance Requirements

Complexity O(n^2).Because while it prints the gitlog command on json, it should also do the same actions converted to html, which will take n^2 steps. That's why the complexity is O(n^2).

2.5 Verification Requirements

This project is not a user input program, so the user won't have to write something, while running the code. The tests should be run manually, as no automation is possible.

2.6 Documentation Requirements

The project should have a README file describing the meaning and usage of the project.
User guide should be provided where the tool installation, usage of all the supported
features.

3 Project Management

3.1 Dependencies, Assumptions, Risks

Risk that can occur are that the consumer took a wrong library or an operator to see the converted data or could not convert the data.

3.2 Schedule and Effort Estimations

The project will be a json file converted to html, where the user will enter the git log command, and the results will be show in the json file, which will then be converted to html.
(Optional) There will be a filtre, where there will only be written the name and the surname of the person who entered the git log command.

3.3 Aceptance Criteria

The acceptance criteria is seeing the project on html, working and running well without error.
