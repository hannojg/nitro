import type {SidebarsConfig} from '@docusaurus/plugin-content-docs';

/**
 * Creating a sidebar enables you to:
 - create an ordered group of docs
 - render a sidebar for each doc of that group
 - provide next/previous navigation

 The sidebars can be generated from the filesystem, or explicitly defined here.

 Create as many sidebars as you want.
 */
const sidebars: SidebarsConfig = {
  tutorialSidebar: [
    'intro',
    'supported-types',
    'comparison',
    'nitrogen',
    'for-users',
    {
      type: 'category',
      label: 'Nitrogen',
      items: [
        'nitrogen/getting-started',
        'nitrogen/primitives',
        'nitrogen/strings',
        'nitrogen/arrays',
        'nitrogen/enums',
      ],
    },
  ],
};

export default sidebars;
