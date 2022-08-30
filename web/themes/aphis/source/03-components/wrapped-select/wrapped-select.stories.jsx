import parse from 'html-react-parser';

import twigTemplate from './wrapped-select.twig';
import data from './wrapped-select.yml';
import './wrapped-select.scss';

const settings = {
  title: 'Components/Wrapped Select'
};

const WrappedSelect = args =>
  parse(
    twigTemplate({
      ...args,
    })
  );
WrappedSelect.args = { ...data };

export default settings;
export { WrappedSelect };
