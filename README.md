# gtest_acoverage_cmake
[![codecov](https://codecov.io/gh/czHappy/gtest_coverage_cmake/branch/master/graph/badge.svg)](https://codecov.io/gh/czHappy/gtest_coverage_cmake)

- C++ gtest单元测试框架，并使用代码测试覆盖率工具生成报告，使用Codecov上传报告。
- 注册Codecov并添加 Settings > Secrets and variables > Actions > New repository secret , token的值可以从 Codecov repo配置指引中获取。
- Actions 跑完之后会生成报告并使用这个token上传报告到 Codecov，在Codecov中可以看到测试情况。

