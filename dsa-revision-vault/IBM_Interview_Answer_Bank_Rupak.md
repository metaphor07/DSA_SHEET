# IBM Recorded Interview: Answer Bank (Rupak Jana)

**Role:** Software Developer, IBM India (req 137964)
**Format:** 1 min to prepare, up to 3 min to answer. Aim for **2:00–2:30**.
**Built from:** Rupak's resume (Airtel internship, OpsPilot AI, ShopSphere, M.Tech thesis, DSA record)

---

## How to use this

1. **Don't memorise word for word.** Read each answer aloud 3–4 times until you know the flow, then speak it in your own words. A memorised script sounds robotic on video.
2. **Each answer is about 230–270 words**, which is roughly 2 minutes at a calm Indian-English pace. The paragraphs follow **Headline → Situation → Task → Actions → Result → Learning**.
3. **Lines marked ✎ under each answer are my guesses.** The resume doesn't give those details, such as team size or exact methods. Change them to what actually happened before the real interview. The live rounds after this will ask follow-up questions, so every detail must be true and something you can explain.
4. **All numbers come from the resume.** Don't add new ones.
5. **Use a different story for each question in one sitting.** The story map below gives a backup for every question.

---

## Numbers to remember (all from the resume)

| Item | Number |
|---|---|
| Airtel: villages with settlement boundaries | **681 villages** |
| Airtel: building footprints processed | **420K+** (say "more than 4 lakh 20 thousand") |
| Airtel: QA retention | **96.9%** passed the checks; exceptions flagged for planners |
| OpsPilot: stockout model | **0.873 PR-AUC / 0.950 ROC-AUC** |
| OpsPilot: delay-risk model | **0.768 ROC-AUC** |
| OpsPilot: data | **11,700 synthetic samples** |
| OpsPilot: tests | **8/8 automated end-to-end tests** |
| LeetCode | **450+ problems, 1800+ rating, Knight badge** |
| CodeChef | **1750+ rating** |
| Flipkart GRID 8.0 | **Semifinalist** |
| CGPA | **7.86** (M.Tech, IIT Delhi), **8.6** (B.Tech, Kurukshetra University) |

---

## Story map: which story for which question

| Story | Short name | Used for |
|---|---|---|
| **A** | Airtel: settlement boundaries for 681 villages | Hardest problem, learning a skill fast, unclear requirements |
| **B** | Airtel: automated cell-placement pipeline | Creative solution, asking for help, adapting to change |
| **C** | Airtel: planners' feedback leads to QA checks (96.9%) | Different perspective, going above and beyond for users |
| **D** | OpsPilot: wrong metric on rare stockouts | Big mistake |
| **E** | OpsPilot: delivery, human approval, tests, honesty about synthetic data | Deadline, leading, convincing, taking responsibility, doing the right thing |
| **F** | ShopSphere: team work | Disagreement, collaboration, a teammate not contributing |
| **G** | Thesis: explainable AI for ECG | Critical feedback, decisions with incomplete information, explaining to non-technical people |
| **H** | Flipkart GRID 8.0 semifinal | Setback or failure |
| **I** | This semester: thesis, courses and placements together | Prioritising |

**One-sitting rule:** if two questions in the same interview point to the same story, take the backup listed under the second question.

---

# Part 1: Motivation and fit

## Q1. Tell me about yourself
*Target 80–100 seconds. Structure: present, past, future.*

> Hello, my name is Rupak Jana. I am from West Bengal, and I am currently pursuing my M.Tech in Telecommunication Technology and Management at IIT Delhi, with a CGPA of 7.86. Before this, I completed my B.Tech in Computer Science and Engineering from Kurukshetra University with a CGPA of 8.6.
>
> I enjoy building software that solves real problems, and I have a strong base in data structures and algorithms. I have solved more than 450 problems on LeetCode, where I have the Knight badge with a rating above 1800, and I was a semifinalist in Flipkart GRID 8.0.
>
> This summer I interned at Bharti Airtel with the network planning team. I built a pipeline that processed more than 4 lakh 20 thousand building footprints to mark settlement boundaries for 681 villages. I also built an automated pipeline that recommends where to place new cell sites. Before that, I built ShopSphere, a full-stack e-commerce platform using React, Node and MongoDB, and OpsPilot AI, a supply-chain decision tool. Right now, for my M.Tech thesis, I am working on explainable AI for ECG-based heart diagnosis.
>
> So I bring a mix of strong coding, full-stack development and practical AI. My next goal is to grow as a software developer who builds reliable products at scale, and that is why I am excited about this role at IBM.

**Prep keywords:** M.Tech IITD 7.86 · B.Tech CSE 8.6 · DSA 450+/Knight/GRID · Airtel 681 villages + cell sites · ShopSphere, OpsPilot · thesis ECG XAI · goal: SDE at IBM

---

## Q2. Why IBM, and why this role?

> I want to join IBM for three main reasons.
>
> First, IBM builds technology that large enterprises trust for their most important work, in banking, healthcare and telecom. What attracts me most is IBM's focus on trustworthy AI. My M.Tech thesis is on explainable and trustworthy AI for ECG diagnosis, and in my OpsPilot project I added explainable risk drivers and a human approval step. IBM works on exactly this problem at product level, for example with watsonx.governance, which monitors AI models for fairness, drift and explainability. So my interest and IBM's direction match well.
>
> Second, I have a telecom connection with IBM's work. I interned at Bharti Airtel, and I read that in October 2025 Airtel partnered with IBM to bring IBM's AI and hybrid cloud technology, like watsonx and Red Hat OpenShift AI, to Airtel Cloud. That showed me how IBM's software reaches real Indian businesses at large scale.
>
> Third, the role itself. As a software developer, I want to write code that runs in production for many customers, not only for a college demo. I have strong DSA and C++, full-stack experience with React and Node, and Python and ML skills. At IBM I can use all of these, and also learn enterprise practices like code reviews, proper testing and working with global teams.
>
> So for me, IBM is a place where I can contribute from day one and also grow into a strong engineer.

**Prep keywords:** 1) trustworthy AI ↔ thesis + OpsPilot ↔ watsonx.governance · 2) Airtel–IBM partnership, Oct 2025 · 3) production code, DSA/C++/full-stack/ML, learn enterprise practices

✎ **Check:** be ready for one follow-up on watsonx.governance and the Airtel–IBM partnership (see the sources at the end).

---

## Q3. Which IBM product or technology excites you most, and why?

> The IBM product that excites me most is watsonx.governance.
>
> Today many companies are building AI models, but the big question is: can we trust them? A model can be accurate on test data and still become biased, or slowly drift when the real-world data changes. watsonx.governance helps companies track their AI models across the full lifecycle and monitor them for fairness, quality, drift and explainability, with alerts when something goes wrong. It also works with models from other providers, not only IBM's.
>
> This excites me because it connects directly to my own work. In my M.Tech thesis on ECG-based cardiac diagnosis, I use methods like Integrated Gradients, SHAP and Grad-CAM to explain why the model made a prediction, and I test whether those explanations stay stable when the ECG signal is noisy. In my OpsPilot project, I showed the top risk drivers behind each stockout prediction, so a manager could understand the prediction before acting on it. In both projects I learned that a good AI system is not only about accuracy; people must be able to check it and trust it.
>
> watsonx.governance does this at enterprise scale. As AI rules and regulations grow, I think this kind of product will become a must-have for every company using AI. As a developer, I would love to work on products where engineering quality and trust both matter this much.

**Prep keywords:** watsonx.governance: trust · fairness/drift/explainability monitoring · ↔ thesis (IG, SHAP, Grad-CAM, noise) · ↔ OpsPilot risk drivers · future must-have

---

## Q4. What are your short-term and long-term goals?
*Target about 90 seconds.*

> In the short term, over the next two to three years, my goal is to become a strong and dependable software developer at IBM. I want to understand how enterprise products are designed, tested and maintained, learn the codebase deeply, and take full ownership of features from design to release. I also want to keep improving my problem-solving and system design skills.
>
> In the long term, around five to seven years, I want to grow into a senior engineer or technical lead who can design complete systems and guide a team. My special interest is reliable and trustworthy AI-powered software, because of my thesis and projects. I want to be the kind of engineer who connects good software engineering with practical AI, so that the products we build are both useful and safe for customers.
>
> IBM is the right place for this journey, because it works across software, AI and hybrid cloud, and gives freshers good learning and mentorship. Step by step, I want to keep learning, deliver good work, and later help junior engineers the same way my seniors and professors helped me.

**Prep keywords:** short: dependable SDE, own features, system design · long: senior engineer/tech lead, trustworthy AI software · IBM = software + AI + cloud + mentorship

---

# Part 2: Ownership and integrity

## Q5. Tell me about a big mistake you made. How did you handle it?
**Story D** · Backup: Story H (GRID)

> One mistake I made was in my OpsPilot AI project, where I judged my stockout prediction model using the wrong metric.
>
> In early 2026, under Prof. Brejesh Lall, I worked on OpsPilot AI, a platform that predicts delays and stockouts in a supply chain. Stockouts are rare events; only a small part of the data has them. I was responsible for the prediction models.
>
> In my first version, I only checked accuracy. The accuracy was very high, so I thought the model was ready. Later, when I looked at the confusion matrix, I saw that the model was missing many real stockouts. It looked good only because most orders were normal. That was my mistake. If I had shown those numbers in the review, the tool would have given false confidence.
>
> I did three things. First, I told my professor honestly that my earlier numbers were misleading. Second, I changed the evaluation to PR-AUC and ROC-AUC, which suit rare events better, and I started tracking how many real stockouts the model actually caught. Third, I fixed the model: I handled the class imbalance and set the decision threshold based on the cost of missing a stockout, then re-checked on held-out data.
>
> In the end, the stockout model reached 0.873 PR-AUC and 0.950 ROC-AUC, and the delay model reached 0.768 ROC-AUC, on 11,700 synthetic samples. More importantly, it now actually caught the rare cases.
>
> My learning is that the metric must match the business problem. Now, before training any model, I first check the class balance and decide the right metric.

**Prep keywords:** S: OpsPilot, rare stockouts · mistake: accuracy only · A: told professor → PR-AUC/ROC-AUC + recall → imbalance + threshold · R: 0.873 / 0.950 / 0.768 · L: metric before model

✎ **Check:** who you told (professor or teammates), and the exact fix you used (class weights, resampling or threshold tuning). Be ready to explain PR-AUC vs ROC-AUC in one line: *PR-AUC focuses on how well you find the rare positive class, so it is more honest when positives are rare.*

---

## Q6. Describe a failure or setback. What did you do next?
**Story H** · Backup: Story D

> A setback I faced was in Flipkart GRID 8.0, where I reached the semifinal but could not go further.
>
> GRID is Flipkart's national-level technology challenge, and a very large number of students take part. I cleared the first round and reached the semifinal, which I was happy about.
>
> In the semifinal, the problems were harder and the time pressure was much higher. I solved some problems, but I got stuck too long on one problem, lost time, and did not qualify for the next round. Honestly, I felt disappointed for a day or two.
>
> Then I did three things. First, I analysed the result honestly. My problem was not only knowledge; it was time management in contests and a few weak topics. Second, I made a fixed practice plan: regular weekly contests on LeetCode and CodeChef, and after every contest I solved the problems I could not finish. Third, I made a simple contest rule for myself: if I am stuck for too long on one problem, I move to the next one and come back later.
>
> This helped a lot. My LeetCode rating went above 1800 with the Knight badge, my CodeChef rating crossed 1750, and I have now solved more than 450 problems. The same discipline also helped me in online assessments, including IBM's.
>
> My learning is that a setback is useful data. Now, after every contest or project, I review what went wrong instead of just moving on.

**Prep keywords:** S: GRID 8.0 semifinal · what happened: stuck on one problem, time · A: honest analysis → weekly contests + upsolving → "stuck → move on" rule · R: 1800+/Knight, 1750+, 450+ · L: setback = data

✎ **Check:** Was GRID solo or a team? What did the semifinal round involve, and when was it? If your ratings came **before** GRID, change the result to "it showed me what to improve, and I am applying it in every contest now."

---

## Q7. Tell me about a time you took responsibility for something that was not strictly your job.
**Story E (tests)** · Backup: Story C (Airtel QA checks)

> In my OpsPilot AI project, I took ownership of end-to-end testing, even though nobody had assigned it to me.
>
> OpsPilot had several parts: delay and stockout prediction, contract retrieval, a recovery optimizer, and a human approval step. Each part was built separately.
>
> My main work was the prediction models. But close to the final review, I noticed a problem. Each part worked alone, but when we connected them, small things kept breaking: a field name was different, a missing value crashed the optimizer, or an API returned an unexpected format. Nobody owned the full flow, so these issues were found late.
>
> So I took it up. First, I wrote down the main user journeys: a disruption comes in, risk is predicted, the related contract clauses are found, a recovery plan is created, and the manager approves it. Second, I wrote automated end-to-end tests for these journeys, which anyone could run with one command before pushing a change. Third, when a test failed, I didn't fix it silently. I shared it with the person who owned that part, and we fixed it together so the same issue didn't come back.
>
> In the end, all 8 out of 8 end-to-end tests passed, and the final demo ran smoothly without last-minute surprises.
>
> My learning is that if something important has no owner, I should own it. Since then, I start writing tests early in a project, not at the end.

**Prep keywords:** S: OpsPilot, parts built separately · problem: integration breaks, no owner · A: user journeys → automated e2e tests, one command → share failures with owners · R: 8/8, smooth demo · L: no owner → I own it; tests early

✎ **Check:** Was OpsPilot a team project? If it was solo, change it to "I built the parts at different times, and integration kept breaking", and use the ShopSphere admin panel or the Airtel QA checks for this question instead.

---

## Q8. Tell me about a time you chose the right thing over the easy thing.
**Story E (honesty)** · Backup: Story C (flagging exceptions instead of hiding them)

> In OpsPilot AI, the easy thing was to present our results as if they were real-world results. I chose to clearly say they came from synthetic data.
>
> We did not have access to real supply-chain data, so we built the models on 11,700 synthetic samples. The results looked very strong: for example, the stockout model reached 0.950 ROC-AUC.
>
> Before the final presentation, there was a temptation to just say "our system predicts stockouts with 95% performance." It would sound impressive, and most people would not ask where the data came from.
>
> But I felt this would be misleading. A company could make real decisions based on that claim. So I did three things. First, I clearly labelled in the report and slides that the data was synthetic, and explained how it was generated and what that means for the results. Second, I made sure the system doesn't act alone: every recovery plan needs human approval, with the risk drivers shown. Third, I wrote a clear limitations section covering what must be done before real use, like testing on real data and monitoring the model for drift.
>
> My professor appreciated this honesty, and today I can defend every number on my resume with confidence, including in interviews like this one.
>
> My learning is that trust is more valuable than impressive numbers. Once people stop trusting your results, nothing else matters. I think this is close to IBM's value of trust and personal responsibility.

**Prep keywords:** easy: present as real · right: label synthetic, explain generation · A: label → human approval → limitations section · R: professor appreciated; I can defend every number · L: trust > impressive numbers

✎ **Check:** "Professor appreciated" is my guess. Use only what actually happened.

---

# Part 3: Teamwork and conflict

## Q9. Tell me about a time you disagreed with a teammate. How did you resolve it?
**Story F** · Backup: Story E (fully automatic vs human approval, Q22)

> I disagreed with a teammate about how to store the shopping cart in our ShopSphere project.
>
> In my B.Tech final year, under Prof. Deepa Sharma, our team built ShopSphere, a full-stack e-commerce platform using React, Node, Express and MongoDB. I was working on the backend APIs and data models.
>
> My teammate wanted to keep the cart only in the browser's local storage, because it was simple and fast to build. I felt the cart should also be saved in the backend database. If a user logs in from another device, the cart would be lost, and the price or stock of a product could change before checkout.
>
> First, instead of arguing, I listened to his reason properly. He was worried about the deadline and the extra API work, which was a fair point. Second, I suggested we test both ideas against real cases: the user moves from phone to laptop, a product goes out of stock, the user logs out and comes back. Seeing both designs side by side made the gaps clear. Third, we agreed on a middle path: guest users keep the cart in local storage, after login it merges into the database, and price and stock are re-checked at checkout. I took responsibility for the extra APIs, so his frontend work did not increase.
>
> The cart then worked across devices, checkout always used the latest price and stock, and we completed the project on time.
>
> My learning is that in a disagreement, focusing on user cases works better than arguing about who is right.

**Prep keywords:** S: ShopSphere, Prof. Deepa Sharma · disagreement: local storage vs DB cart · A: listened (deadline worry) → tested against real user cases → middle path (guest local, merge on login, re-check at checkout), I took the extra APIs · R: works across devices, on time · L: user cases > who is right

✎ **Check:** Was ShopSphere a team project, and with how many people? Was the cart actually the disagreement? If you had a different real disagreement, such as SQL vs MongoDB or REST design, use that in the same structure.

---

## Q10. Describe a time you asked someone for help because they had expertise you lacked.
**Story B** · Backup: Story A (asking the GIS team about map data)

> During my Airtel internship, I asked a senior network planner to help me understand how mobile sites actually cover an area.
>
> This was in summer 2026 with the SAE team at Bharti Airtel in Gurgaon. I was building an automated pipeline to recommend where new cell sites should be placed.
>
> My background is computer science and ML, so I was comfortable with the data side, but I did not know radio planning in depth.
>
> First, I tried on my own. I read the basics, and my first version treated every site like a simple circle of coverage. The results did not look right to me, but I wasn't sure why. Second, instead of asking a vague question, I prepared specific examples on the map and went to a senior planner in the team. He explained that real sites cover in directional sectors, and that coverage depends on the direction and the surroundings. Third, I turned his explanation into logic in my pipeline: directional coverage, uncovered-area analysis and population demand. I also made the output GIS-compatible, so he and the other planners could open it directly in their own tools.
>
> As a result, the pipeline produced site recommendations that were much closer to how planners actually think, and they could review them easily.
>
> My learning is that asking early, with a specific question, saves a lot of time. Domain experts know things that are not in the data, and respecting their time with a clear question makes them happy to help.

**Prep keywords:** S: Airtel cell placement · gap: radio planning knowledge · A: tried myself (circle model) → specific examples to senior planner → coded directional coverage + uncovered area + demand; GIS output for planners · R: realistic, reviewable recommendations · L: ask early, specific

✎ **Check:** who you actually asked (mentor, manager or planner), and whether your first version really used a "circle" model.

---

## Q11. How do you work in a team? Give an example where collaboration made the result better.
**Story F** · Backup: Story E (team integration in OpsPilot)

> In a team, I like three things: clear roles, short regular updates, and making it easy for others to do their part. ShopSphere is a good example.
>
> In my B.Tech final year, under Prof. Deepa Sharma, we built ShopSphere, a full-stack e-commerce platform. My teammate was building the React frontend, and I was building the backend APIs and MongoDB data models.
>
> The risk was that frontend and backend would be built separately, and at the end nothing would connect properly.
>
> So we did three things together. First, before writing code, we agreed on the API contract: the endpoints for products, cart and checkout, and the exact request and response format, written in a shared document. Second, I created mock responses for the APIs, so my teammate could build the product search, filters and cart screens in parallel without waiting for me. Third, we had a short daily check-in of ten to fifteen minutes about what was done, what was blocked, and whether anything in the contract needed to change.
>
> Because of this, integration was smooth, and we finished user authentication, product search and filtering, the cart and the checkout flow, plus an admin panel for managing products. My teammate also gave me useful feedback on response formats that made the frontend simpler, which I would not have thought of alone.
>
> My learning is that good collaboration is about removing waiting time for others and agreeing on interfaces early. I would bring the same habits to a team at IBM.

**Prep keywords:** style: clear roles, short updates, unblock others · S: ShopSphere frontend/backend split · A: API contract first → mock responses for parallel work → daily 10–15 min check-in · R: smooth integration, all features + admin · L: remove waiting, agree on interfaces early

✎ **Check:** your real role split and team routine in ShopSphere.

---

## Q12. Tell me about a time a team member was not contributing. What did you do?
**Story F** · Backup: none needed; this question is rare

> In my ShopSphere project, one teammate was not making progress on the admin interface, and I had to handle it without hurting the team.
>
> We were building a full-stack e-commerce platform in my B.Tech final year. The admin panel, where products are created, updated, deleted and managed, was assigned to one teammate. After about two weeks, there was very little progress, and our review date was coming close.
>
> First, instead of complaining to the professor or in the group, I talked to him privately and asked if something was blocking him. He said he was not confident with React and was also busy with backlog exam preparation. Second, I helped him get started: I set up the basic React structure for the admin pages, explained how our product APIs worked, and showed him one complete example, the "add product" form. Third, we broke his work into small weekly goals, so progress was visible and he did not feel overloaded. I also told the team about the new plan, so nobody felt it was unfair.
>
> After that, he picked up speed. The admin panel with product creation, update, deletion and catalog management was completed on time, and he contributed properly in the final demo.
>
> My learning is that when someone is not contributing, there is usually a reason. Talking privately first, supporting them and breaking the work into smaller tasks works much better than blaming.

**Prep keywords:** S: ShopSphere admin panel stuck · A: private talk (weak in React + exams) → set up structure + one full example → small weekly goals, told the team · R: admin panel done on time · L: find the reason, support, smaller tasks

✎ **Check:** this is the most "invented" story. Use it only if something similar really happened, in ShopSphere, OpsPilot, Flipkart GRID or a course project. If nothing like it happened, use any real team situation and keep the same structure.

---

# Part 4: Problem solving and innovation

## Q13. Describe a creative or innovative solution you came up with.
**Story B** · Backup: Story G (using three explanation methods and checking where they agree)

> A creative solution I built was the automated cell-placement pipeline during my Airtel internship.
>
> Airtel's network planning team decides where to place new cell sites. Much of this used to be done by planners looking at coverage maps and population information by hand, which is slow when there are many villages.
>
> My task was to build an automated way to suggest good locations for new sites.
>
> The obvious approach was to just put sites wherever coverage is missing. But that alone could place a site in an empty field where nobody lives. So my idea was to combine three signals. First, uncovered-area analysis: find the gaps in the current coverage. Second, population demand: using population and building-footprint data, give higher priority to gaps where more people actually live. Third, directional coverage logic: real sites cover in specific directions, so I modelled coverage by direction and chose the location and direction that cover the most uncovered demand. Finally, I made the output GIS-compatible, so planners could open the recommendations directly in their own tools and check them.
>
> As a result, the pipeline automatically generated site recommendations that planners could review on a map, instead of starting from a blank map every time.
>
> My learning is that innovation is often about combining simple signals in a smart way, and about designing the output for the tool the user already works in.

**Prep keywords:** S: Airtel site planning, manual maps · obvious: fill gaps only, which puts sites in empty fields · A: uncovered area + population demand + directional coverage → GIS output · R: automatic, reviewable recommendations · L: combine simple signals; fit the user's tool

✎ **Check:** how planning was done before your tool, and what GIS tool the planners used (for example QGIS).

---

## Q14. What is the hardest technical problem you have solved?
**Story A** · Backup: Story G (thesis)

> The hardest technical problem I have solved was automatically drawing settlement boundaries for 681 villages during my Airtel internship.
>
> For network planning, Airtel needs to know where people actually live inside a village, the settlement area, not just the official village boundary that also includes fields and empty land. The data I had was large and messy: more than 4 lakh 20 thousand building footprints, plus population and land-cover data.
>
> My task was to turn this raw data into clean, planning-ready regions automatically. The difficulty was that every village is different. Some are dense, some have scattered houses, and some nearby villages almost touch each other.
>
> First, I started small. I took a few villages, plotted the data on a map, and studied the patterns before writing the full pipeline. Second, I grouped buildings that were close to each other into settlements using spatial clustering, so a few far-away houses would not stretch the boundary. I used land-cover data to remove fields and water bodies, then converted each group into a boundary shape. Third, I made it work at full scale, and I added automatic quality checks so that unusual results were flagged for review instead of being silently accepted.
>
> In the end, the pipeline generated settlement boundaries for all 681 villages from the 420K+ footprints, and 96.9% of the regions passed the quality checks.
>
> My learning is to break a big, messy problem into a small one first, look at the data visually, and never trust automatic output without checks.

**Prep keywords:** S: Airtel, settlement ≠ village boundary · data: 420K+ footprints, population, land cover · A: small sample on a map → clustering + land-cover filter → polygons → scale + QA flags · R: 681 villages, 96.9% · L: small first, visualise, always add checks

✎ **Check:** your exact method (for example DBSCAN or buffer-and-merge clustering) and libraries (GeoPandas, Shapely). Know one line on **why clustering**: houses close together belong to one settlement, and density-based clustering ignores isolated points.

---

## Q15. Tell me about a time you had to make a decision with incomplete information.
**Story G** · Backup: Story E (choosing synthetic data because real data was not available)

> In my M.Tech thesis, I had to decide how to judge whether my model's explanations are correct, even though there is no ground truth for that.
>
> My thesis, under Prof. Brejesh Lall, is on explainable and trustworthy AI for ECG-based cardiac diagnosis. A 1D-CNN model predicts the most probable heart condition from the ECG, and explanation methods highlight which part of the signal drove the prediction.
>
> My task was to choose how to explain and evaluate the model. The problem was that nobody can directly say "this is the correct explanation". Different methods, like Integrated Gradients, SHAP and Grad-CAM, can highlight different parts of the same ECG, and I could not wait for doctors to mark every signal.
>
> So I did three things. First, instead of betting on one method, I decided to use all three and check where they agree and disagree. Second, I defined measurable tests: faithfulness, meaning that if I remove the highlighted part, the prediction should change clearly; stability, meaning that similar heartbeats should get similar explanations; and robustness, meaning the explanations should hold up under realistic ECG noise. Third, I kept the decision easy to change, by writing the code so methods can be swapped, and I plan to validate the important cases with clinical guidance later.
>
> This gave me a clear and repeatable way to compare the methods, and it is now a main part of my thesis evaluation.
>
> My learning is that with incomplete information, it's better to make a reasonable decision, define how you will measure it, and keep it reversible, than to wait for perfect information.

**Prep keywords:** S: thesis ECG XAI · problem: no ground-truth explanation · A: use 3 methods and compare agreement → faithfulness/stability/robustness tests → swappable code, later clinical check · R: repeatable evaluation framework · L: decide, measure, keep reversible

✎ **Check:** whether you plan any clinician validation. Use one-line definitions: *Integrated Gradients* adds up the effect of each input point from a blank baseline to the real signal. *SHAP* shares the prediction among the inputs, based on game theory. *Grad-CAM* uses the gradients of the last convolution layer to show the important time regions.

---

# Part 5: Learning and feedback

## Q16. Tell me about a time you had to learn a new skill quickly.
**Story A (geospatial)** · Backup: Story G (learning XAI and the ECG domain for the thesis)

> I had to learn geospatial data analysis very quickly at the start of my Airtel internship.
>
> My background is computer science and ML, and I had never worked with maps, coordinate systems or building-footprint data before. The internship was only about two months, so there was no time to learn slowly.
>
> My goal was to learn enough in the first couple of weeks to start building the real pipeline.
>
> First, I learned by doing. I took a small sample of villages and practised with Python geospatial libraries, checking every result visually on a map. Second, I focused on the basics that cause most errors in this field: coordinate systems, measuring area and distance in metres instead of degrees, and spatial joins between buildings, population and land-cover data. Third, I asked the team specific questions whenever I was stuck, and I kept a small notes file of what I learned and the mistakes I made, so I did not repeat them.
>
> Because of this, within the first few weeks I was building the actual pipeline. By the end of the internship, I had processed more than 4 lakh 20 thousand building footprints into settlement boundaries for 681 villages, and also built the automated cell-placement pipeline.
>
> My learning is that to learn fast, I should start with a small real problem, focus on the fundamentals, and ask questions early. I used the same approach for my ECG thesis, and I would use it to learn a new codebase at IBM.

**Prep keywords:** S: Airtel, no GIS background, about 2 months · A: small sample + visual checks → fundamentals (CRS, metres vs degrees, spatial joins) → specific questions + notes file · R: real pipeline in weeks; 420K+, 681, cell placement · L: small real problem, fundamentals, ask early

✎ **Check:** the libraries and tools you actually used, and how long it took you to start the real work.

---

## Q17. Give an example where you sought out a different perspective or feedback, and how you implemented it.
**Story C** · Backup: Story G (Q18)

> At Airtel, I asked the network planners, who were the actual users of my work, to review my first settlement-boundary results, and their feedback changed my design.
>
> After my first version of the boundary pipeline, the results looked fine to me from the data and ML side. But I knew planners would use these regions for real network decisions, so I wanted their view before going further.
>
> My goal was to make sure the output was not just technically correct, but actually useful for planning.
>
> First, I sought out their perspective. I showed sample villages on the map and asked them directly: "Would you plan with this? What looks wrong?" Second, they pointed out things I had missed. In some cases a boundary joined two separate settlements, or covered only part of a village, and trusting such cases blindly could lead to wrong planning. Third, and this is how I implemented the feedback, I built spatial quality validation checks on things like size, building density and overlap with neighbouring regions. Results that failed were not silently dropped; they were flagged for planner review. I also kept the output GIS-compatible, so they could check flagged cases easily.
>
> As a result, 96.9% of the regions passed the quality checks and were ready to use, and the unusual cases went to planners for review. They trusted the output more because nothing was hidden.
>
> My learning is that the user's perspective catches problems that my metrics cannot. Now I share early versions with users instead of waiting for a perfect final version.

**Prep keywords:** S: Airtel boundaries v1 looked fine to me · sought: planners' review ("Would you plan with this?") · feedback: merged or partial settlements · implemented: QA checks (size, density, overlap) + flag for review + GIS output · R: 96.9% passed, flagged rest · L: share early with users

✎ **Check:** what planners actually said, and which checks you built. Check the meaning of **96.9% QA retention**. I've read it as "96.9% of regions passed the checks and were kept".

---

## Q18. Tell me about a time you received critical feedback. What did you change?
**Story G** · Backup: Story C

> My thesis supervisor told me that my explanation heatmaps were not enough proof, and that feedback changed my whole approach.
>
> In the early stage of my M.Tech thesis on explainable AI for ECG diagnosis, I trained a 1D-CNN model and used Grad-CAM to highlight which part of the ECG signal the model focused on. The heatmaps looked very convincing, and I was quite happy with them.
>
> When I showed them to Prof. Brejesh Lall, he said that a heatmap that looks good is not proof. He asked how I knew it reflected what the model really uses, and whether it would stay the same on a noisy ECG. Honestly, my first feeling was that I had already done good work, but I realised he was right.
>
> First, I accepted the feedback and asked follow-up questions to understand exactly what kind of evidence he expected. Second, I read work on evaluating explanations and added three evaluations to my thesis: faithfulness, stability and robustness under realistic ECG noise. Third, I added Integrated Gradients and SHAP alongside Grad-CAM, so that I could compare the methods instead of trusting only one.
>
> As a result, my thesis now has a proper evaluation section, and the work is much more scientific and trustworthy. That is exactly what a medical AI system needs.
>
> My learning is that critical feedback is where the real improvement comes from. Now, before presenting anything, I ask myself, "How would someone challenge this?"

**Prep keywords:** S: thesis, Grad-CAM heatmaps looked good · feedback: "nice heatmap ≠ proof; noise?" · A: accepted + clarified → faithfulness/stability/robustness → add IG + SHAP · R: proper evaluation, trustworthy · L: "How would someone challenge this?"

✎ **Check:** this is my guess at how the evaluation part of your thesis came about. Use the real conversation if it was different.

---

# Part 6: Adaptability and pressure

## Q19. Tell me about a time you delivered under a tight deadline without compromising quality.
**Story E** · Backup: Story B (Airtel second pipeline in the remaining weeks, Q20)

> OpsPilot AI had to be built end to end in about three months, alongside my coursework, and I delivered it without compromising quality.
>
> From February to April 2026, under Prof. Brejesh Lall, I built OpsPilot AI, a supply-chain disruption platform. The scope was big: delay and stockout prediction, contract retrieval, constrained recovery optimisation, human approval, explainable risk drivers and what-if analysis.
>
> My task was to deliver a working end-to-end system by the final review.
>
> First, I prioritised. I listed all the features and separated the must-haves, which were prediction, contract retrieval, the recovery plan and approval, from the nice-to-haves. I built the simplest version of the full flow first, and then improved each part. Second, I handled the data problem quickly: real supply-chain data was not available, so instead of losing weeks searching, I generated 11,700 synthetic samples and clearly mentioned this in the report. Third, I protected quality with testing. I set up automated end-to-end tests early and ran them before every change, so new features never broke old ones.
>
> As a result, I delivered on time. The stockout model reached 0.873 PR-AUC and 0.950 ROC-AUC, the delay model reached 0.768 ROC-AUC, the explainable risk drivers and what-if analysis were working, and all 8 out of 8 end-to-end tests passed.
>
> My learning is that under a deadline, I build a thin end-to-end version first and protect quality with tests. Cutting tests to save time is a false saving.

**Prep keywords:** S: OpsPilot, Feb–Apr 2026, big scope + courses · A: must-haves first, thin end-to-end → synthetic data (11,700) instead of waiting → e2e tests early · R: on time, 0.873/0.950/0.768, 8/8 · L: thin e2e first; tests are not optional

✎ **Check:** the real deadline and what you cut or deferred.

---

## Q20. Describe a time you had to adapt when plans or requirements changed suddenly.
**Story B** · Backup: Story E

> During my Airtel internship, the focus of my work changed midway, from settlement boundaries to cell-site placement, and I had to adapt quickly.
>
> In the first part of the internship, my work was creating settlement boundaries for villages. Midway, the team's priority shifted: planners also needed recommendations for where to place new cell sites, using those regions.
>
> So I had a new problem, less time left, and my first work still had to be finished properly.
>
> First, I did not panic. I spoke with my mentor to understand the new goal clearly and what "done" would look like for the planners. Second, I reused what I had. The settlement boundaries and population data became the demand input for the new pipeline, so my earlier work was not wasted. Third, I planned the remaining weeks in stages. I finished and handed over the boundary pipeline with proper documentation, then built cell placement step by step: uncovered-area analysis first, then population demand, then directional coverage logic.
>
> By the end of the internship, I had delivered both: settlement boundaries for 681 villages, and an automated cell-placement pipeline that produced GIS-compatible site recommendations.
>
> My learning is that when plans change, the first step is to clarify the new goal, then reuse what already exists, and deliver in small stages. Change is normal in real projects, and I now plan my work so it can be reused.

**Prep keywords:** S: Airtel, boundaries → cell placement midway · A: clarify the goal with mentor → reuse boundaries as demand input → stage plan (hand over + doc, then 3 steps) · R: both delivered (681 + site pipeline) · L: clarify, reuse, stage

✎ **Check:** did the scope really change midway, or were both tasks planned from the start? If they were planned, frame it as "the second task came with less time than expected", or use Story E.

---

## Q21. How do you prioritise when several tasks are due at the same time? Give an example.
**Story I** · Backup: Story E

> I prioritise by deadline and impact, I protect fixed focus time, and I communicate early. This semester is a good example.
>
> Right now I am in my third semester of M.Tech at IIT Delhi. At the same time, I have my thesis on explainable AI for ECG under Prof. Brejesh Lall, my coursework, and placement season with online assessments from many companies.
>
> I can't drop any of these, so I need a system.
>
> First, at the start of every week, I list all my tasks with their deadlines and sort them by deadline and impact. Things like an online assessment date or an assignment submission can't move, so they come first. Thesis work has milestones with my professor, so I plan backwards from those. Second, I keep fixed time blocks: DSA practice in the morning, thesis and coursework in the day, and revision or company-specific preparation in the evening. Third, I communicate early. If a placement test clashes with a thesis meeting, I inform my professor in advance and reschedule, instead of missing it or doing both badly.
>
> Because of this, my thesis work is moving forward, my coursework is on track, and I cleared IBM's online assessment and reached this round.
>
> My learning is that prioritisation is not about doing everything at once; it is about deciding what must happen this week, protecting focus time for it, and telling people early when something has to move.

**Prep keywords:** method: deadline + impact, focus blocks, communicate early · S: thesis + courses + placements · A: weekly list sorted → morning DSA / day thesis / evening prep → tell professor early about clashes · R: thesis moving, courses on track, cleared IBM OA · L: decide, protect, communicate

✎ **Check:** your actual routine. Keep it simple and true.

---

# Part 7: Leadership and influence

## Q22. Tell me about a time you led a team to solve a problem.
**Story E** · Backup: Story F (ShopSphere, if you led it)

> I led my team in the OpsPilot AI project, where our main problem was that the different parts were not fitting together.
>
> In early 2026, under Prof. Brejesh Lall, we built OpsPilot AI, a supply-chain disruption platform. It had several parts: delay and stockout prediction, contract retrieval, recovery optimisation and a human approval step, and different members were building different parts.
>
> In the early weeks, everyone was working separately, and when we tried to connect the parts, things kept failing, because each part expected data in a different format. As the person coordinating the project, I had to fix this and keep us on schedule.
>
> First, I defined clear interfaces. I wrote a shared data and API contract, so every part knew exactly what input it would get and what output it must give. Second, I started short check-ins twice a week about what was done, what was blocked, and who needed help. When someone was blocked, I paired with them instead of just pushing the deadline. Third, I set up automated end-to-end tests for the full flow, so integration problems were caught on the same day, not at the end.
>
> As a result, all parts were integrated smoothly, all 8 out of 8 end-to-end tests passed, and we delivered the prediction models, explainable risk drivers and what-if analysis on time.
>
> My learning is that leading a team is less about giving orders and more about clear interfaces, removing blockers and keeping progress visible to everyone.

**Prep keywords:** S: OpsPilot, parts don't fit · role: coordinator · A: shared API/data contract → check-ins twice a week + pairing → e2e tests · R: integrated, 8/8, on time · L: interfaces, unblock, visible progress

✎ **Check:** team size and your actual role. **If OpsPilot was solo, don't use this.** Use ShopSphere, GRID, a college fest or club, or any group you organised, with the same structure.

---

## Q23. Describe a time you convinced others to adopt your idea.
**Story E (human-in-the-loop)** · Backup: Story F (cart design, Q9)

> In OpsPilot AI, I convinced my team to add a human approval step, instead of letting the system act fully automatically.
>
> OpsPilot recommends recovery actions when a supply-chain disruption is predicted, for example changing the supplier or speeding up an order.
>
> Some teammates wanted the system to be fully automatic: find the best plan and execute it directly. It would be faster and would look impressive in the demo. My concern was that a wrong automatic decision could cost real money or break contract terms. Also, our models were trained on synthetic data, so we should not blindly trust them.
>
> First, instead of arguing in general, I showed two or three concrete examples where the model's prediction was borderline and an automatic action would have been costly. Second, I proposed a design that kept their concern about speed in mind: the system prepares the plan with explainable risk drivers and the related contract clauses, and the manager only has to approve it, so it is still fast. Third, I added what-if analysis, so the manager can check things like "what if the delay is shorter than predicted?" before approving.
>
> The team agreed, and the final platform had human-in-the-loop approval, explainable risk drivers and what-if analysis. Together these made the tool more trustworthy, and that became one of its strongest points in the review.
>
> My learning is that people are convinced by examples and by a solution that also respects their concern, not by arguments alone.

**Prep keywords:** S: OpsPilot recovery actions · disagreement: fully automatic vs approval · A: concrete borderline examples → approve-only design (fast) + risk drivers + contract clauses → what-if · R: adopted; strongest point · L: examples + respect their concern

✎ **Check:** whether this discussion really happened, and with whom (teammates or professor). If OpsPilot was solo, frame it as convincing your professor or reviewers about the human-in-the-loop design.

---

## Q24. Tell me about a time you explained a technical topic to a non-technical person.
**Story G** · Backup: Story A (explaining clustering results to planners)

> I had to explain my thesis, explainable AI for ECG diagnosis, to my family, who are not from a technical background.
>
> When I told them my thesis is about AI for heart diagnosis, they asked two questions: "Will the computer replace the doctor?" and "How does it even decide?"
>
> My task was to explain it simply, without any jargon, and also explain why explainability matters.
>
> First, I used a simple picture. An ECG is just a line graph of the heartbeat, and my model is like a student who has studied thousands of ECGs and learned which patterns usually mean which heart condition. Second, to explain explainability, I used a school example: when a teacher asks a student to underline the line in the textbook where the answer came from, the underline shows whether the student really understood. My methods do the same thing: they underline the part of the ECG that made the model decide. Third, I checked their understanding by asking them to explain it back to me in their own words, and I made one point clear: the AI does not replace the doctor. It suggests the most likely condition and the confirmatory tests, like Holter monitoring or echocardiography, and the doctor decides.
>
> They understood it well, and they even asked, "What if the underline is wrong?" That is exactly the faithfulness check I am doing in my thesis.
>
> My learning is to use everyday examples, avoid jargon, and check understanding by asking people to explain back. At IBM this will help me when I talk to product managers or clients.

**Prep keywords:** S: family asks about the thesis · A: ECG = line graph, model = student → explainability = underlining the textbook line → explain back + AI suggests, doctor decides (Holter, echo) · R: "What if the underline is wrong?" = faithfulness · L: everyday examples, explain back

✎ **Check:** who you actually explained it to (family, a friend or a junior). Keep the analogies.

---

# Part 8: User and client focus

## Q25. Tell me about a time you went above and beyond for a user, client or stakeholder.
**Story C (GIS-ready output)** · Backup: Story E (what-if analysis for managers)

> During my Airtel internship, I went beyond the basic task to make sure the planners could actually use my output easily and trust it.
>
> The basic requirement was to generate settlement regions and site recommendations for the network planning team.
>
> I could have just handed over a data file and finished my task. But I thought about how the planners would actually use it. They work on maps in their GIS tools, and they need to trust the result before making planning decisions.
>
> So I did three extra things. First, I made all outputs GIS-compatible, so planners could open them directly in their own tools without any conversion. Second, I added spatial quality checks, and instead of hiding the unusual cases, I flagged them clearly for planner review, so they knew exactly which results needed a human look. Third, I documented how the pipeline works and how to run it again, so the team could keep using it after my internship ended, without depending on me.
>
> As a result, 96.9% of the regions passed the quality checks and were ready to use, the exceptional cases were clearly marked, and the team had a pipeline they could rerun on their own.
>
> My learning is that a task is truly complete only when the user can use it easily and trust it, not just when my code runs. I want to bring this user-first thinking to IBM's clients.

**Prep keywords:** basic: hand over a data file · extra: GIS-compatible → QA + flagged exceptions → documentation to rerun · R: 96.9%, flagged, reusable · L: done = the user can use and trust it

✎ **Check:** did you write documentation or a handover? If not, replace that with something else you actually did.

---

## Q26. Describe a time requirements were unclear. How did you clarify them before building?
**Story A** · Backup: Story E (OpsPilot's open-ended "decision intelligence" scope)

> At the start of my Airtel internship, the requirement was just to "create planning-ready regions for villages", which was not clear enough to start building.
>
> I was with the SAE team, and the data was building footprints, population and land cover for many villages. But "planning-ready" could mean many things: which boundary, how detailed, what format, and what counts as a good result.
>
> Before writing a big pipeline, I wanted to be sure I was building the right thing.
>
> First, I asked the planners specific questions: what exactly they would use the regions for, whether they needed the full village boundary or only the area where people live, what format they work with, and what kind of mistakes would hurt their planning the most. Second, I built a small sample for a few villages and showed it to them on a map before scaling up. Their feedback helped me fix the definition early. Third, I wrote down the agreed definition as a simple checklist, and that checklist later became my automatic quality checks.
>
> Because of this, I avoided a lot of rework. The final pipeline covered 681 villages from more than 4 lakh 20 thousand building footprints, and 96.9% of the regions passed the quality checks.
>
> My learning is that when requirements are unclear, I should ask specific questions, show a small example early, and write down the agreed definition. A small sample shown early saves weeks of rework later.

**Prep keywords:** S: "planning-ready regions", vague · A: specific questions (use, boundary type, format, worst errors) → small sample on a map → written checklist → QA checks · R: avoided rework; 681, 420K+, 96.9% · L: ask, show a sample early, write it down

✎ **Check:** the original wording of your task. Don't use this story together with Q17 in the same sitting.

---

# Part 9: Responsible AI

## Q27. How do you use AI tools in your work, and how do you check their output?

> I use AI tools regularly, but I treat their output like a first draft from a junior teammate, not as the final answer.
>
> I use them mainly in three ways: to write boilerplate code faster, like FastAPI routes or React components; to understand a new library or an error message quickly; and to get ideas for test cases and edge cases.
>
> For checking, I follow three rules. First, I verify everything: I run the code, write tests, and check the official documentation, especially for anything important. Second, I protect data: I never paste company or private data into public AI tools. During my Airtel internship, for example, I only asked generic technical questions and never shared internal data. Third, I take ownership: if code goes into my commit, I must understand every line of it, and I am responsible for it.
>
> Here is a real example of why this matters. While working on geospatial code, an AI suggestion calculated village areas directly on latitude and longitude coordinates. The areas came out as tiny decimal values, which looked wrong to me. I checked the documentation and found that the area must be calculated after converting to a projected coordinate system in metres. I fixed it and added a check that areas stay in a realistic range. If I had trusted it blindly, all my boundary sizes would have been wrong.
>
> So AI makes me faster, but my judgment, my testing and my responsibility don't change.

**Prep keywords:** AI = first draft from a junior · uses: boilerplate, new libraries/errors, test ideas · rules: verify (run, tests, docs) → protect data (nothing from Airtel) → own every line · example: area in degrees → projected CRS in metres + range check · AI = speed; responsibility = mine

✎ **Check:** name the tools you actually use (ChatGPT, Copilot or Claude) if asked. Swap the example for your own real "AI was wrong" moment if you have a better one.

---

# Revision cheat sheet: memorise only this

| Story | One-line memory |
|---|---|
| **A** Airtel boundaries | Settlement ≠ village · 420K+ footprints · small sample → clustering + land-cover → QA flags · **681 villages, 96.9%** |
| **B** Airtel cell placement | Gaps alone put sites in fields · uncovered area + population demand + directional coverage · GIS output |
| **C** Planners' feedback | "Would you plan with this?" · merged or partial settlements · QA checks + flag for review · **96.9%** |
| **D** OpsPilot metric mistake | Accuracy fooled me (rare stockouts) · told professor · PR-AUC, imbalance, threshold · **0.873 / 0.950 / 0.768** |
| **E** OpsPilot delivery | Must-haves first · synthetic data **11,700** (labelled honestly) · human approval + what-if · e2e tests **8/8** |
| **F** ShopSphere | Local-storage vs DB cart → user cases → guest local + merge on login · API contract + mocks · admin-panel teammate |
| **G** Thesis ECG | 1D-CNN · IG + SHAP + Grad-CAM · "Nice heatmap ≠ proof" → faithfulness, stability, robustness under noise · underlining analogy |
| **H** Flipkart GRID | Semifinal, stuck too long · upsolving + "move on" rule · **1800+ Knight, 1750+, 450+** |
| **I** Semester | Deadline × impact · morning DSA / day thesis / evening prep · tell professor early |

**In the 1-minute prep:** read the question twice → pick the story letter → write 5 keywords → say the headline in your head → look at the lens.

---

## Sources for the IBM facts used in the answers

- [IBM Newsroom: Bharti Airtel announces a strategic partnership with IBM to augment Airtel Cloud (15 Oct 2025)](https://newsroom.ibm.com/2025-10-15-bharti-airtel-announces-a-strategic-partnership-with-ibm-to-augment-airtel-cloud)
- [IBM: watsonx.governance, monitoring fairness, quality, explainability and drift](https://www.ibm.com/watson/trustworthy-ai)
- [Maginative: IBM unveils watsonx.governance (works with models from all sources)](https://www.maginative.com/article/ibm-unveils-watsonx-governance-to-govern-generative-ai-and-build-trust/)
