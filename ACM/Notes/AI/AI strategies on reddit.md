## 1. 别把第一版输出当成“差不多得了” (Stop treating the first output as 'close enough')

- **Reddit 观点：** 很多人的习惯是拿到第一版平庸的回复后，直接在上面继续修改。Reddit 用户 _ultrathink-art_ 指出：“**错误是会复合叠加的。** 你的第 5 步错误，其实是建立在前面 4 个没有核对的错误之上的，最后想改对反而比重写更难。” [[1](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/)]
- **高手做法：** 严格走“单步验证”流程。AI 给出第一步大纲后，仔细检查、修正，确认完全无误后，再发送：“很好，基于这个修改后的版本，我们开始下一步。” [[1](https://www.reddit.com/r/PromptEngineering/comments/1nt7x7v/after_1000_hours_of_prompt_engineering_i_found/), [2](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/)]

## 2. 多用“否定限制”，比“正面要求”更高效 (Negative constraints shape output faster)

- **Reddit 观点：** 用户 _TheseTradition3191_ 提到，与其花大篇幅告诉 AI 应该怎么写，不如**先告诉它“绝对不要做什么”**。 [[1](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/)]
- **高手做法：** 在提示词最后加上一行“反向避坑指南”，例如：_“不要使用‘在当今快节奏的世界中’这种 AI 腔调”、“不要使用被动语态”、“不要直接给出结论，先推导”_。划定红线能瞬间让输出的质量翻倍。 [[1](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/)]

## 3. 把 AI 当作“第二审阅人”，而不是“初稿打字机” (Second pass, not first draft)

- **Reddit 观点：** 很多人把最难的“从零到一”丢给 AI，结果出来一堆套话。Reddit 顶尖答主 _Born-Exercise-2932_ 分享：“最改变我工作流的做法，是**自己写一个非常粗糙、毫无文采的草稿，然后让 AI 来‘找茬’**。”
- **高手做法：** 自己先花 3 分钟列出核心逻辑，然后对 AI 说：_“这是我的粗糙想法。请作为挑剔的审查员，帮我找出逻辑漏洞，指出我忽略了什么，并帮我重新梳理结构。”_ [[1](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/)]

## 4. 停止让 AI 凭空“想象”，让它“转换现实” (Stop asking AI to imagine. Ask it to transform reality)

- **Reddit 观点：** 在一篇关于[高效使用 Claude 的万字长文](https://www.reddit.com/r/claude/comments/1t00jvq/how_to_actually_use_ai_effectively/)中，楼主强调：“如果你不知道自己要什么，AI 就会替你发明要求，而那绝对不是你想要的。”
- **高手做法：** **拒绝模糊的单行提问**（如“帮我写个营销方案”）。高手总是给 AI 提供充足的“弹药”——行业数据、客户聊天截图、竞品文档，然后对 AI 说：_“基于这些真实数据，帮我提炼出 3 个痛点。”_ [[1](https://www.reddit.com/r/AIAssisted/), [2](https://www.reddit.com/r/claude/comments/1t00jvq/how_to_actually_use_ai_effectively/), [3](https://www.reddit.com/r/EntrepreneurRideAlong/comments/1rugf0u/whats_your_best_ai_productivity_trick/), [4](https://www.reddit.com/r/PromptEngineering/comments/1plbkua/i_mapped_every_ai_prompting_framework_i_use_this/)]

## 5. 使用 XML 标签来整理复杂逻辑 (Use XML tags for structure)

- **Reddit 观点：** 在 Reddit 的提示词工程板块中，几乎所有人都极力推荐使用类似 `<background>`、`<constraints>` 这样的 XML 标签来喂给 AI 数据。
- **高手做法：** Markdown 的井号（#）和加粗有时会让 AI 在面对超长文本时产生解析混乱，而 XML 标签能建立清晰的“提取边界”，让 AI 100% 精确理解你的意图。 [[1](https://www.reddit.com/r/PromptEngineering/comments/1uged7m/best_source_of_learning_prompt_engineering/), [2](https://www.reddit.com/r/PromptEngineering/comments/1t42u52/i_spent_6_months_testing_every_major_prompting/)]

---

如果你想去 Reddit 围观原帖，可以搜索以下几个关键词（长按可复制）：

- `"What's the best advice about using AI that genuinely changed"`（最改变认知的 AI 建议）
- `"How to Actually Use AI Effectively r/claude"`（如何真正高效使用 AI）
- `"I mapped every AI prompting framework I use"`（大神整理的提示词全栈框架） [[1](https://www.reddit.com/r/PromptEngineering/comments/1plbkua/i_mapped_every_ai_prompting_framework_i_use_this/), [2](https://www.reddit.com/r/artificial/comments/1t96p2d/whats_the_best_advice_about_using_ai_that/), [3](https://www.reddit.com/r/claude/comments/1t00jvq/how_to_actually_use_ai_effectively/)]
